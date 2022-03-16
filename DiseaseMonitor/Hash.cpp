#include "Hash.hpp"
#include "DiseaseData.h"
#include "CountryData.h"
#include <stdio.h>
#include <string.h>

Hash::Hash(DataType t, int size, int bucketSize) : type(t) {
    tableSize = size;
    hashTable = new Bucket*[tableSize];

    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = new Bucket(type, bucketSize);
    }
}

Hash::~Hash() {
    int i;
    for (i = 0; i < tableSize; i++) {
        delete hashTable[i]; // = new Bucket(bucketSize);
    }
    delete [] hashTable;
}

DataType Hash::getDataType() {
    return type;
}

int Hash::HashFuction(string key) {
    int index = 0;

    //    cout << "My key is " << key << endl;
    // cout << tableSize << endl;
    int size = key.length() + 1;

    for (int i = 0; i < size; i++) {
        index += ((int) key[i]*13 + 97);
    }

    index %= 211;
    //cout << index << endl;

    index %= tableSize;

    //cout << index << endl;

    return index;

}

bool Hash::putItemOnHashTable(Record *record) {
    string key;

    if (type == TYPE_RECORD) {
        key = record->getRecordID();
    }
    if (type == TYPE_DISEASE) {
        key = record->getDiseaseID();
    }
    if (type == TYPE_COUNTRY) {
        key = record->getCountry();
    }

    int position = HashFuction(key);
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    //cout << "HASH TABLE - put item on " << position << " position" << endl;

    if (type == TYPE_RECORD) {
        TableData*temp = findItemOnHashTable(key);
        if (temp == NULL) {
            //cout << "Creating Record " << endl;
            hashTable[position]->saveRecord(record);
            //record->Print();
            return true;
        } else {
            //cout << "Duplicate Record " << endl;
            return false;
        }
    }

    if (type == TYPE_DISEASE) {
        // cout << "I am at disease " << endl;
        DiseaseData * temp = (DiseaseData*) findItemOnHashTable(key);
        if (temp == NULL) {
            hashTable[position]->saveRecord(record);
        } else {
            temp->setData(record);
            // temp->addPatient();
        }
    }
    if (type == TYPE_COUNTRY) {
        CountryData * temp = (CountryData*) findItemOnHashTable(key);
        if (temp == NULL) {
            hashTable[position]->saveRecord(record);
        } else {
            temp->setData(record);
            // temp->addPatient();
        }
    }
    //cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    return true;
}

TableData* Hash::findItemOnHashTable(string key) {

    int position = HashFuction(key);
    //cout << "i should find it on " << position << endl;
    return (hashTable[position]->findItem(key));
}

void Hash::printHashTable() {

    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i]->getNumOfRecords())
            //cout << "At " << i << " position I have this list " << endl;
            hashTable[i]->printRecords();
    }
}

void Hash::printCases() {
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i]->getNumOfRecords())
            //cout << "At " << i << " position I have this list " << endl;
            hashTable[i]->printRecords();
    }
}

void Hash::globalDisease(Date& d1, Date& d2) {
    for (int i = 0; i < tableSize; i++) {
        Bucket *bucket = hashTable[i];
        do {
            for (int j = 0; j < bucket->getNumOfRecords(); j++) {
                DiseaseData * temp = (DiseaseData*) bucket->getTableData(j);
                Tree * tree = temp->getTree();
                int n = tree->frequency(d1, d2);
                cout << temp->getKey() <<  " " << n << endl;
            }
            bucket = bucket->getNext();
        }while(bucket != NULL);
    }
}

void Hash::printPatients(){
    for (int i = 0; i < tableSize; i++) {
        Bucket *bucket = hashTable[i];
        do {
            for (int j = 0; j < bucket->getNumOfRecords(); j++) {
                DiseaseData * temp = (DiseaseData*) bucket->getTableData(j);
                temp->PrintPatients();
            }
            bucket = bucket->getNext();
        }while(bucket != NULL);
    }
}