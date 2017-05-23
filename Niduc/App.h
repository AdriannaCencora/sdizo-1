#pragma once

#include "stdafx.h"

class App final
{
public:
	App() = delete;
	App(std::string inputFileName, std::string outputFileName) : m_inputFileName(inputFileName), m_outputFileName(outputFileName) {};
	~App() = default;

	void readInputFile();
	void generateErrorMask();
	void applyErrors();
	void writeToOutputFile();
private:
	std::string m_inputFileName;
	std::string m_outputFileName;
	std::list<bool> m_inputData;
	std::list<bool> m_errorMask;
	std::list<bool> m_outputData;

	long long int getBadBits();
	float generatePropability();
};

