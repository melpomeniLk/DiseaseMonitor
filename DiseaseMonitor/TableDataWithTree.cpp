#include "TableDataWithTree.h"

TableDataWithTree::TableDataWithTree() {
    tree = new Tree();
    cases = 0;
}

TableDataWithTree::~TableDataWithTree() {
    delete tree;
}   

void TableDataWithTree::setData(Record *info){
    //cout << "I just inserted a case " << endl;
    tree->insertData(info);
    cases++;
}

void TableDataWithTree::Print() {
    cout << getKey() << " " << cases << endl;
    //tree->printTree();
}

void TableDataWithTree::addCase(){
    cases++;
}
