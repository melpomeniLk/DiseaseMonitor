#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <iostream>

using namespace std;

struct HeapNode {
    string id; // disease or country
    int counter;
    HeapNode *left, *right, *parent;
};

class Heap {
protected:
    HeapNode *root;
    int height, numOfNodes;
    void deleteHeap(HeapNode*);
    void insertNode(HeapNode*, string, int ,int);
    void swim(HeapNode*);
    void sink(HeapNode*);
    void printNode(HeapNode*);
    HeapNode* findLastNode(HeapNode *current, int nodesCounter, int h);
public:
    Heap();
    virtual ~Heap();

    void insert(string id); // insert with counter equal to 1
    HeapNode* find(HeapNode *, string);
    void removeMax();
    int getNumOfNodes(){return numOfNodes;}
    void printTree();
};

#endif /* HEAP_H */

