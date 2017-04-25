#include "stdafx.h"
#include "BST.h"

void BST::addElement(int value)
{
	if (root == nullptr)
	{
		root = make_unique<Node>();
		root->value = value;
		return;
	}

	Node* tmp = root.get();

	while (true)
	{
		if (value < tmp->value)
		{
			if (tmp->left == nullptr)
			{
				tmp->left = make_unique<Node>();
				tmp->left->value = value;
				tmp->left->parent = tmp;
				return;
			}
			tmp = tmp->left.get();
		}
		else
		{
			if (tmp->right == nullptr)
			{
				tmp->right = make_unique<Node>();
				tmp->right->value = value;
				tmp->right->parent = tmp;
				return;
			}
			tmp = tmp->right.get();
		}
	}
}

void BST::removeElement(int value)
{
	Node* toDelete = getNode(root.get(), value);
	if (toDelete != nullptr)
		removeNode(toDelete);

	return;
}

void BST::clearStructure()
{
	root.reset();
}

bool BST::findValue(int toFind)
{
	Node* searchPoint = root.get();
	while (searchPoint != nullptr && searchPoint->value != toFind)
	{
		if (toFind < searchPoint->value)
			searchPoint = searchPoint->left.get();
		else
			searchPoint = searchPoint->right.get();
	}
	return (searchPoint != nullptr);
}

void BST::printData()
{
	printNode(string(""), string(""), root);
}

void BST::fixBalance()
{
}

void BST::rotateLeft(Node * axis)
{
}

void BST::rotateRight(Node * axis)
{
}

void BST::makeLinear()
{
}

void BST::makeBalanced()
{
}

BST::Node * BST::getNode(Node * startPoint, int value)
{
	while (startPoint != nullptr && startPoint->value != value)
	{
		if (value < startPoint->value)
			startPoint = startPoint->left.get();
		else
			startPoint = startPoint->right.get();
	}
	return startPoint;
}

BST::Node * BST::getMin(Node * searchPoint)
{
	while (searchPoint->left != nullptr)
		searchPoint = searchPoint->left.get();
	return searchPoint;
}

BST::Node * BST::getMax(Node * searchPoint)
{
	while (searchPoint->right != nullptr)
		searchPoint = searchPoint->right.get();
	return searchPoint;
}

BST::Node * BST::getPredecessor(Node * searchPoint)
{
	if (searchPoint->left != nullptr)
		return getMax(searchPoint->left.get());
	Node* parentNode = searchPoint->parent;
	while (parentNode != nullptr && parentNode->right.get() != searchPoint)
	{
		searchPoint = parentNode;
		parentNode = searchPoint->parent;
	}
	return parentNode;
}

BST::Node * BST::getSuccessor(Node * searchPoint)
{
	if (searchPoint->right != nullptr)
		return getMin(searchPoint->right.get());
	Node* parentNode = searchPoint->parent;
	while (parentNode != nullptr && parentNode->left.get() != searchPoint)
	{
		searchPoint = parentNode;
		parentNode = searchPoint->parent;
	}
	return parentNode;
}

void BST::removeNode(Node * toDelete)
{
	Node* childNode = nullptr;
	Node* parentNode = nullptr;

	//No child case
	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		parentNode = toDelete->parent;
		if (parentNode->left.get() == toDelete)
			parentNode->left.reset();
		else
			parentNode->right.reset();
		return;
	}

	//One child case
	if ((toDelete->left == nullptr) != (toDelete->right == nullptr))
	{
		parentNode = toDelete->parent;

		if (parentNode->left.get() == toDelete)
		{
			if (toDelete->left != nullptr)
				parentNode->left = move(toDelete->left);
			else
				parentNode->left = move(toDelete->right);
			parentNode->left->parent = parentNode;
			
		}
		else
		{
			if (toDelete->left != nullptr)
				parentNode->right = move(toDelete->left);
			else
				parentNode->right = move(toDelete->right);
			parentNode->right->parent = parentNode;
		}
		return;
	}

	//To child case
	if (toDelete->left != nullptr && toDelete->right != nullptr)
	{
		childNode = getSuccessor(toDelete);

		toDelete->value = childNode->value;

		removeNode(childNode);
	}
}

void BST::printNode(std::string & sMiddle, std::string & sBefore, unique_ptr<Node> &currNode)
{
	string s;
	if (currNode != nullptr)
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), currNode->right);

		s = s.substr(0, sMiddle.length() - 2);

		cout << s << sBefore << currNode->value << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), currNode->left);
	}
}

