#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include "Date.hpp"
#include "Record.h"
#include "Heap.h"
#include "RecordLL.hpp"


using namespace std;

struct TreeNode {
    Date entryDate;
    TreeNode *left, *right;
    RecordLL *records;
    int height;
//    List<Rercord> list
};

class Tree {
protected:
    TreeNode *root;
    bool empty;
    TreeNode* insertTreeNode(Record*, TreeNode*);
    void insertNode(Record*);
    void printNode(TreeNode*);
public:
    Tree();
    ~Tree();
    void insertData(Record*);
    void printTree();
    int getHeight(TreeNode *current);
    int getBalance(TreeNode *current);
    int max(int , int);
    TreeNode* leftRotation(TreeNode *);
    TreeNode* rightRotation(TreeNode *);
    
    //Record * getData(TreeNode&);
    void deleteTree(TreeNode*);
    
    void topK_diseases(int k, string country);
    void dfs1_diseases(TreeNode * current, Heap * heap);
    
    void topK_Countries(int k, string disease);
    void dfs1_Countries(TreeNode * current, Heap * heap);

    void topK_diseasesBetween(int k, string country, Date d1, Date d2);
    void dfs1_diseasesBetween(TreeNode * current, Heap * heap, Date d1, Date d2);

    void topK_CountriesBetween(int k, string disease, Date d1, Date d2);
    void dfs1_CountriesBetween(TreeNode * current, Heap * heap, Date d1, Date d2);
    
    
    
    // disease frequency
    int frequency(Date d1, Date d2);
    
    int frequencyCountry(string country, Date d1, Date d2);
    
    int dfs_frequency(TreeNode * current, Date d1, Date d2);
 
    int dfs_frequencyCountry(TreeNode * current,string country, Date d1, Date d2);
};

#endif /* TREE_H */

