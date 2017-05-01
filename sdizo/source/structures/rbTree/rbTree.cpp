#include "stdafx.h"
#include "rbTree.h"

using namespace std;

void rbTree::addElement(int value)
{
	if (root == nullptr)
	{
		root = make_unique<Node>();
		root->value = value;
		++size;
		root->color = Color::Black;
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
				tmp->left->color = Color::Red;
				++size;
				if (!checkColor(tmp->left.get()))
					fixColors(tmp->left.get());
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
				tmp->right->color = Color::Red;
				++size;
				if (!checkColor(tmp->right.get()))
					fixColors(tmp->right.get());
				return;
			}
			tmp = tmp->right.get();
		}
	}
}

void rbTree::removeElement(int value)
{
	Node* toDelete = getNode(root.get(), value);
	if (toDelete != nullptr)
	{
		removeNode(toDelete);
		--size;
	}
}

void rbTree::clearStructure()
{
	root.reset();
	size = 0;
}

bool rbTree::findValue(int toFind)
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

void rbTree::printData()
{
	printNode(string(""), string(""), root);
}

bool rbTree::checkColor(Node * toCheck)
{
	if (toCheck->parent == nullptr && toCheck->color == Color::Red)
		return false;
	if (toCheck->parent != nullptr)
	{
		if (toCheck->parent->color == Color::Red)
			return false;
	}

	return true;
}

void rbTree::fixColors(Node * startNode)
{
	if (startNode->parent != nullptr)
	{
		if (startNode->parent->parent != nullptr)
		{
			Node* uncle;
			Node* grandParent = startNode->parent->parent;
			bool guardianSet = false;

			if (isLeftChild(startNode->parent))
				uncle = grandParent->right.get();
			else
				uncle = grandParent->left.get();

			if (uncle == nullptr)
			{
				uncle = createGuardianNode(grandParent);
				guardianSet = true;
			}

			if (uncle->color == Color::Red)
				fixColorsRedUncle(startNode);
			else
				if (isLeftChild(startNode->parent))
					fixColorsBlackUncleLeftChild(startNode);
				else
					fixColorsBlackUncleRightChild(startNode);

			if(guardianSet)
				deleteGuardianNode(uncle);
		}
	}


	if(root->color == Color::Red)
		fixColorsRedRoot();
	
}

void rbTree::fixColorsRedRoot()
{
	cout << "red root correction! " << endl;
	root->color = Color::Black;
}

void rbTree::fixColorsRedUncle(Node * startNode)
{
	Node* uncle = getUncle(startNode);
	if (uncle == nullptr)
		return;
	Node* grandParent = startNode->parent->parent;

	uncle->color = Color::Black;
	startNode->parent->color = Color::Black;
	grandParent->color = Color::Red;

	fixColors(grandParent);
}

void rbTree::fixColorsBlackUncleRightChild(Node * startNode)
{
	Node* parent = startNode->parent;
	Node* grandParent = startNode->parent->parent;

	if (isLeftChild(startNode))
	{
		rotateRight(parent);
		startNode = parent;
		parent = startNode->parent;
	}
	rotateLeft(grandParent);

	rbTree::Color tmp = parent->color;
	parent->color = grandParent->color;
	grandParent->color = tmp;

	fixColors(parent);

}

void rbTree::fixColorsBlackUncleLeftChild(Node * startNode)
{
	Node* parent = startNode->parent;
	Node* grandParent = startNode->parent->parent;
	
	if (isRightChild(startNode))
	{
		rotateLeft(parent);
		startNode = parent;
		parent = startNode->parent;
	}
	rotateRight(grandParent);

	rbTree::Color tmp = parent->color;
	parent->color = grandParent->color;
	grandParent->color = tmp;

	fixColors(parent);

}

rbTree::Node * rbTree::createGuardianNode(Node * parent)
{
	if (parent->left == nullptr)
	{
		parent->left = make_unique<rbTree::Node>();
		parent->left->parent = parent;
		parent->left->color = Color::Black;
		return parent->left.get();
	}
	if (parent->right == nullptr)
	{
		parent->right = make_unique<rbTree::Node>();
		parent->right->parent = parent;
		parent->right->color = Color::Black;
		return parent->right.get();
	}
	return nullptr;
}

void rbTree::deleteGuardianNode(Node * guardian)
{
	unique_ptr<Node>* guardianUnique = getUniqueNode(guardian);
	guardianUnique->reset();

}

void rbTree::rotateLeft(Node * axis)
{
	if (axis->right == nullptr)
		return;

	bool isAxisLeftChild = isLeftChild(axis);

	//Creating hooks
	unique_ptr<rbTree::Node>* axisUniquePtr = getUniqueNode(axis);
	unique_ptr<rbTree::Node> axisUnique = move(*axisUniquePtr);

	Node* rightChild = axis->right.get();
	unique_ptr<rbTree::Node>* rightChildUniquePtr = getUniqueNode(rightChild);
	unique_ptr<rbTree::Node> rightChildUnique = move(*rightChildUniquePtr);

	//Moving childs
	if (rightChild->left != nullptr)
	{
		axis->right = move(rightChild->left);
		axis->right->parent = axis;
	}
	rightChild->left = move(axisUnique);

	//Resettings parents child pointers
	if (axis->parent != nullptr)
	{
		if (isAxisLeftChild)
			axis->parent->left = move(rightChildUnique);
		else
			axis->parent->right = move(rightChildUnique);
	}

	//Setting parents
	rightChild->parent = axis->parent;
	axis->parent = rightChild;

	//Resetting root to correct place if needed
	if (rightChild->parent == nullptr)
		root = move(rightChildUnique);
}

void rbTree::rotateRight(Node * axis)
{
	if (axis->left == nullptr)
		return;

	bool isAxisLeftChild = isLeftChild(axis);

	//Creating hooks
	unique_ptr<rbTree::Node>* axisUniquePtr = getUniqueNode(axis);
	unique_ptr<rbTree::Node> axisUnique = move(*axisUniquePtr);

	Node* leftChild = axis->left.get();
	unique_ptr<rbTree::Node>* leftChildUniquePtr = getUniqueNode(leftChild);
	unique_ptr<rbTree::Node> leftChildUnique = move(*leftChildUniquePtr);

	//Moving childs
	if (leftChild->right != nullptr)
	{
		axis->left = move(leftChild->right);
		axis->left->parent = axis;
	}
	leftChild->right = move(axisUnique);

	//Resettings parents child pointers
	if (axis->parent != nullptr)
	{
		if (isAxisLeftChild)
			axis->parent->left = move(leftChildUnique);
		else
			axis->parent->right = move(leftChildUnique);
	}

	//Setting parents
	leftChild->parent = axis->parent;
	axis->parent = leftChild;

	//Resetting root to correct place if needed
	if (leftChild->parent == nullptr)
		root = move(leftChildUnique);
}

rbTree::Node * rbTree::getNode(Node * startPoint, int value)
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

std::unique_ptr<rbTree::Node>* rbTree::getUniqueNode(Node * toGet)
{
	if (toGet->parent == nullptr)
		return &root;
	Node* parent = toGet->parent;
	if (parent->left.get() == toGet)
		return &(parent->left);
	else
		return &(parent->right);
}

rbTree::Node * rbTree::getMin(Node * searchPoint)
{
	while (searchPoint->left != nullptr)
		searchPoint = searchPoint->left.get();
	return searchPoint;
}

rbTree::Node * rbTree::getMax(Node * searchPoint)
{
	while (searchPoint->right != nullptr)
		searchPoint = searchPoint->right.get();
	return searchPoint;
}

rbTree::Node * rbTree::getUncle(Node * child)
{
	if (child->parent == nullptr)
		return nullptr;
	if (child->parent->parent == nullptr)
		return nullptr;
	Node* uncle;
	Node* grandParent = child->parent->parent;
	if (isLeftChild(child->parent))
		uncle = grandParent->right.get();
	else
		uncle = grandParent->left.get();

	return uncle;
}

rbTree::Node * rbTree::getPredecessor(Node * searchPoint)
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

rbTree::Node * rbTree::getSuccessor(Node * searchPoint)
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

bool rbTree::isLeftChild(Node * child)
{
	if (child->parent == nullptr)
		return false;

	Node* parent = child->parent;
	return (parent->left.get() == child);
}

bool rbTree::isRightChild(Node * child)
{
	if (child->parent == nullptr)
		return false;

	Node* parent = child->parent;
	return (parent->right.get() == child);
}

void rbTree::removeNode(Node * toDelete)
{
	Node* childNode = nullptr;
	Node* parentNode = nullptr;

	//Root case
	if (toDelete == root.get())
	{
		this->clearStructure();
		return;
	}

	//No child case
	if (toDelete->left == nullptr && toDelete->right == nullptr)
	{
		parentNode = toDelete->parent;
		if (parentNode->left.get() == toDelete)
			parentNode->left.reset();
		else
			parentNode->right.reset();
		--size;
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
		--size;
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

void rbTree::printNode(std::string & sMiddle, std::string & sBefore, unique_ptr<Node>& currNode)
{
	string s;
	if (currNode != nullptr)
	{
		s = sMiddle;
		if (sBefore == (string(1, (char)47) + string(1, (char)126)))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)47)) + string(1, (char)126), currNode->right);

		s = s.substr(0, sMiddle.length() - 2);

		if (currNode->color == Color::Red)
			cout << s << sBefore << "(" << currNode->value << ")" << endl;
		else
			cout << s << sBefore << currNode->value << endl;

		s = sMiddle;
		if (sBefore == (string(1, (char)92)) + string(1, (char)126))
			s[s.length() - 2] = ' ';
		printNode(s + (char)124 + " ", (string(1, (char)92)) + string(1, (char)126), currNode->left);
	}
}
