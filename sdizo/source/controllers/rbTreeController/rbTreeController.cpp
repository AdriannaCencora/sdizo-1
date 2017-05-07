#include "stdafx.h"
#include "rbTreeController.h"

#include <vector>


#include "../../views/rbTree/rbTreeMenu.h"
#include "../../structures/rbTree/rbTree.h"

void rbTreeController::init()
{
	structure = std::make_unique<rbTree>();
	menu = std::make_unique<rbTreeMenu>();
}

void rbTreeController::testStructure()
{
	rbTree* rbt = (rbTree*)structure.get();
	int added;
	int deleted;
	int checkIndex;
	std::string message;
	std::vector<int> input;
	std::vector<int> inputToPrint;
	std::vector<int> deletedV;
	int startSize;

	rbt->clearStructure();

	while (rbt->isBalanced()) 
	{
		system("cls");
		// Prepare a tree
		rbt->clearStructure();
		input.clear();
		inputToPrint.clear();
		deletedV.clear();

		for (int i = 0; i < 1000; ++i)
		{
			added = rand() % 1000000 + 1;

			if (rbt->findValue(added))
			{
				--i;
				continue;
			}

			rbt->addElement(added);
			input.push_back(added);
		}

		startSize = input.size();
		inputToPrint = input;

		for (int i = 0; i < floor(2 * startSize / 3); ++i)
		{
			checkIndex = rand() % input.size();
			deleted = input.at(checkIndex);
			rbt->removeElement(deleted);
			input.erase(input.begin() + checkIndex);
			deletedV.push_back(deleted);
			if (!rbt->isBalanced())
				break;
		}
		
	}

	cout << "Input\n";
	for (int i : inputToPrint)
		message.append(std::to_string(i) + " ");
	message.append("\n");
	cout << message;

	message.clear();

	cout << "delete order\n";
	for (int i : deletedV)
		message.append(std::to_string(i) + " ");
	message.append("\n");
	cout << message;
	system("pause");
}
