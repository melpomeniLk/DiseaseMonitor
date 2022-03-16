#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>
#include <string.h>
#include "Bucket.hpp"
#include "Record.h"
#include "DataType.h"

using namespace std;

class Hash {
private:
    int tableSize, bucketSize;
    Bucket ** hashTable;
    DataType type;
public:
    Hash(DataType t, int, int);
    ~Hash();
    int HashFuction(string);
    bool putItemOnHashTable(Record *record);
    TableData* findItemOnHashTable(string key);
    void printHashTable();
    void printCases();
    void globalDisease(Date&,Date&);
    void printPatients();
    DataType getDataType();
};




#endif