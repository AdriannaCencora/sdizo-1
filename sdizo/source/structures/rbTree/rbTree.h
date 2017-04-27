#pragma once
#include "../bst/BST.h"

class rbTree :
	public BST
{
public:
	rbTree() = default;
	virtual ~rbTree() = default;

	virtual void addElement(int value);
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);
	virtual void printData();

private:

	enum Color { Black, Red };

	struct Node {
		Node* parent = nullptr;
		unique_ptr<Node> right = nullptr;
		unique_ptr<Node> left = nullptr;
		int	  value;
		Color color;
	};

	unique_ptr<Node> root = nullptr;
	unsigned int size = 0;

	void rotateLeft(Node* axis);
	void rotateRight(Node* axis);
	Node* getNode(Node* startPoint, int value);
	unique_ptr<Node>* getUniqueNode(Node* toGet);
	Node* getMin(Node* searchPoint);
	Node* getMax(Node* searchPoint);
	bool isLeftChild(Node* child);
	bool isRightChild(Node* child);
	void removeNode(Node* toDelete);
	void printNode(std::string &sMiddle, std::string &sBefore, unique_ptr<Node> &currNode);
};

