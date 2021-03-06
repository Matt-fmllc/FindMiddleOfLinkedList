// FindMiddleOfLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


typedef struct _Node
{
	int		iVal;
	_Node*	pNext;

}Node;

Node* pListRoot = nullptr;

bool AddNode(Node* _pNode)
{
	if (!_pNode)
		return false;
	if (pListRoot == nullptr) {
		_pNode->pNext = nullptr;
		pListRoot = _pNode;
	}
	else {
		_pNode->pNext = pListRoot;
		pListRoot = _pNode;
	}

	return true;
}

int FindMiddleRabbitHare()
{
	if (pListRoot == nullptr) {
		return -1;
	}
	Node* pNode1 = pListRoot;
	Node* pNode2 = pListRoot;

	int iCounter = 1;
	bool bDone = false;
	while (!bDone) {
		if (pNode2->pNext == nullptr || pNode2->pNext->pNext == nullptr) {
			bDone = true;
		}
		else {
			iCounter++;
			pNode2 = pNode2->pNext->pNext;
		}
	}

	return iCounter;
}

int FindMiddleBruteForce()
{
	if (pListRoot == nullptr)
		return -1;
	Node* pNode = pListRoot;

	int iCounter = 1;
	bool bDone = false;
	while (!bDone) {
		if (pNode->pNext == nullptr) {
			bDone = true;
			iCounter++;
		}
		else {
			pNode = pNode->pNext;
			iCounter++;
		}
	}

	return iCounter/2;
}

int main()
{
	int InputArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//int InputArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int InputArray[] = { 1, 2, 3};
	//int InputArray[] = { 1, 2 };
	//int InputArray[] = { 1 };
	int iArrayCount = sizeof(InputArray) / sizeof(int);

	Node* pNode = nullptr;
	for (int x = 0; x < iArrayCount; x++) {
		pNode = new Node();
		pNode->iVal = InputArray[x];
		AddNode(pNode);
	}

	int iResult = -1;
	iResult = FindMiddleBruteForce();
	printf("\nMiddle of linked list = %d", iResult);
	iResult = FindMiddleRabbitHare();
	printf("\nMiddle of linked list = %d", iResult);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
