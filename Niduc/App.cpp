#include "stdafx.h"
#include "App.h"

using namespace std;


void App::readInputFile()
{
	ifstream inputFile;
	inputFile.open(m_inputFileName, std::ifstream::in);

	if (!inputFile.is_open())
		throw new logic_error("B³¹d podczas otwierania pliku");

	string line;
	bool data;
	long long int linesRead = 0;
	while (getline(inputFile, line))
	{
		istringstream iss(line);
		while (iss >> data)
			m_inputData.push_back(data);
		++linesRead;
	}
	inputFile.close();

	cout << "Read " << linesRead << " lines." << endl;
}

void App::generateErrorMask()
{
	double check = 100;
	double p = 0.02777;
	double r = 0.25;
	int iteration = 0;
	bool lastBit = true;

	while (check >= 10)
	{
		m_errorMask.clear();
		while (m_inputData.size() != m_errorMask.size())
		{
			if (lastBit)
			{
				m_errorMask.push_back(1);
				lastBit = generatePropability() > p;
			}
			else
			{
				m_errorMask.push_back(0);
				lastBit = generatePropability() > (1 - r);
			}
		}

		double theoPackLossRate = 1 - r / (p + r);

		
		double actPackLossRate = ((double)getBadBits()/ (double)m_inputData.size());

		check = abs(theoPackLossRate - actPackLossRate) / theoPackLossRate * 100;

		cout << "Iteration: " << iteration++ << ", theo: " << theoPackLossRate << ", act: " << actPackLossRate << ", check: " << check << endl;
	}
}

void App::applyErrors()
{
	if (m_errorMask.size() != m_inputData.size())
		throw new logic_error("D³ugoœæ maski b³êdów nie zgadza siê z d³ugoœci¹ danych wejœciowych");
	list<bool>::iterator errorBit = m_errorMask.begin();
	list<bool>::iterator inputBit = m_inputData.begin();
	for(; errorBit != m_errorMask.end() && inputBit != m_inputData.end(); ++errorBit, ++inputBit)
		m_outputData.push_back((!(*errorBit)) != (*inputBit));
}

void App::writeToOutputFile()
{
	ofstream outputFile;
	outputFile.open(m_outputFileName, std::ofstream::out | std::ofstream::trunc);

	if (!outputFile.is_open())
		throw new logic_error("B³¹d podczas otwierania pliku");

	for (auto bit : m_outputData)
		outputFile << (int)bit << endl;

	outputFile.close();
}

long long int App::getBadBits()
{
	long long int badBits = 0;
	for (auto bit : m_errorMask)
		if (!bit)
			++badBits;
	return badBits;
}

float App::generatePropability()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
