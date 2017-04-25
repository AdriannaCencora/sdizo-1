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
	if (root == nullptr)
		return;

	Node* tmp = getNode(root.get(), value);
	
	if (tmp->parent != nullptr)
	{
		//if (tmp->parent);
	}
}

void BST::clearStructure()
{
	root.reset();
}

bool BST::findValue(int toFind)
{
	return false;
}

void BST::printData()
{
	printNode(string(""), string(""), root);
}

void BST::fixBalance()
{
}

BST::Node * BST::getNode(Node * startPoint, int value)
{
	while (startPoint != nullptr && startPoint->value == value)
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

