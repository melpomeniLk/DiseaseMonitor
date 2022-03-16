
#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <string>
#include "Record.h"

using namespace std;

class TableData {
public:
    TableData();
    virtual ~TableData();
    
    string getKey() const {
        return key;
    }

    void setKey(string key) {
        this->key = key;
    }

    bool isUsed() const {
        return used;
    }

    void setUsed(bool used) {
        this->used = used;
    }

    virtual void setData(Record *record) = 0;
    
    virtual void Print() = 0;

    virtual void addCase() = 0;
    
    virtual void exitPatient(string) = 0;
private:
    string key;
    bool used;
    
};

#endif /* TABLEDATA_H */

