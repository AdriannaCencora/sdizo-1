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
	std::string message;
	std::vector<int> input;

	rbt->clearStructure();

	while (rbt->isBalanced()) 
	{
		rbt->clearStructure();
		input.clear();
		for (int i = 0; i < 100; ++i)
		{
			added = rand() % 10000 + 1;

			if (rbt->findValue(added))
			{
				--i;
				continue;
			}

			rbt->addElement(added);
			input.push_back(added);
			if (!rbt->isBalanced())
				break;
		}
	}

	for (int i : input)
		message.append(std::to_string(i) + " ");
	message.append("\n");
	cout << message;
	system("pause");
}
