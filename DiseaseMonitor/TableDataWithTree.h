
#ifndef TABLEDATAWITHTREE_H
#define TABLEDATAWITHTREE_H

#include "TableData.h"
#include "Tree.h"
//#include "TreeInt.h"


class TableDataWithTree : public TableData {
public:
    TableDataWithTree();
    virtual ~TableDataWithTree();
    virtual void setData(Record*);
    void Print();
    void addCase();
    virtual void exitPatient(string) = 0;
    
    int getCases() const {
        return cases;
    }

    void setCases(int cases) {
        this->cases = cases;
    }

    Tree* getTree() const {
        return tree;
    }

    void setTree(Tree* tree) {
        this->tree = tree;
    }

private:
    Tree * tree;
    int cases;
};

#endif /* TABLEDATAWITHTREE_H */

