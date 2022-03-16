#ifndef Bucket_hpp
#define Bucket_hpp

#include <iostream>
#include "TableData.h"
#include "DataType.h"
#include "Record.h"

using namespace std;



class Bucket {
private:
    Bucket *next;
    int size, numOfRecords;
    TableData **tableData;
    DataType type;
    int bucketSize;
public:
    Bucket(DataType, int);
    ~Bucket();
    void saveRecord(Record* );
    int findRecord(string);
    TableData *findItem(string key);
    Bucket *getNext(){return next;}
    void printRecord(int);
    void printRecords();
    bool isBucketFull(Bucket*);
    int getNumOfRecords() const {
        return numOfRecords;
    }
    TableData* getTableData(int);
};


#endif