#ifndef RecordLL_hpp
#define RecordLL_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Record.h"
using namespace std;


struct ListNode{
	Record *record;
	ListNode *next;
};

class RecordLL{
protected:
	ListNode *head;
	ListNode *tail;
	int numOfNodes;
public:
	RecordLL();
	~RecordLL();
	void InsertNode(Record*);
	int FindNode(string);
	void printNode(string);
	void PrintList();
	int getNumOfNodes();
        ListNode* getNext(ListNode *t){return t->next;}
        ListNode* getHead(){return head;}
	char* getSenderID();
	char* getReceiverID();
	bool isListEmpty();
};

#endif
