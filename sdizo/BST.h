#pragma once
#include "GenericStructure.h"

using namespace std;

class BST :
	public GenericStructure
{
public:
	BST() = default;
	virtual ~BST() = default;

	virtual void addElement(int value) { throw NotImplementedException(); };
	virtual void removeElement(int value);
	virtual void clearStructure();
	virtual bool findValue(int toFind);
	virtual void printData();
	virtual void fixBalance();

private:

	

	struct Node {
		Node* parent;
		unique_ptr<Node> right;
		unique_ptr<Node> left;
		int	  value;
	}
	
};

