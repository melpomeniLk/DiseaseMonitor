#include "Bucket.hpp"
#include "RecordData.h"
#include "DiseaseData.h"
#include "CountryData.h"
#include "DataType.h"

#include <stdio.h>
#include <string.h>

using namespace std;

Bucket::Bucket(DataType t, int bs) : type(t), bucketSize(bs) {
    size = (bs - sizeof (int*)) / sizeof (*tableData);
    next = NULL;
    numOfRecords = 0;
    tableData = new TableData*[size];
    for (int i = 0; i < size; i++) {
        if (t == TYPE_RECORD) {
            tableData[i] = new RecordData();
            // cout << "RecordData just created " << endl;
        } else if (t == TYPE_DISEASE) {
            tableData[i] = new DiseaseData();
        } else if (t == TYPE_COUNTRY) {
            tableData[i] = new CountryData();
        }
    }

    //    cout << "I am Bucket Constructor, I got this " << bs << " BucketSize " << endl;
    //    cout << "so I will have " << size << " records-" << endl;
    //    cout << "Current num of records is " << numOfRecords << endl;
    //    cout << "my Bucket size is " << sizeof (Bucket) << endl;
}

Bucket::~Bucket() {
    for (int i = 0; i < size; i++) {
        delete tableData[i];
    }
    delete [] tableData;

    if (next != NULL) {
        delete next;
    }
}

void Bucket::saveRecord(Record *data) {
    //cout << "Put record on Bucket " << endl;

    Bucket * temp = this;
    while (isBucketFull(temp) && temp->next != NULL) {
        temp = temp->next;
    }
    
    if (isBucketFull(temp)) { // last node
        //cout << "My last bucket is full " << endl;
        temp->next = new Bucket(type, bucketSize);
        temp = temp->next;
    }

    temp->tableData[temp->getNumOfRecords()]->setData(data);

    temp->numOfRecords++;
    //cout << "Bucket checked " << temp->numOfRecords << endl;
}

int Bucket::findRecord(string key) {
    for (int i = 0; i < numOfRecords; i++) {
        if (tableData[i]->getKey() == key) {
            return i;
        }
    }
    return -1;
}

TableData * Bucket::findItem(string key) {
    Bucket *temp = this;
    do {
        int loops = temp->getNumOfRecords();
        for (int i = 0; i < loops; i++) {
            if (temp->tableData[i]->getKey() == key) {
                return temp->tableData[i];
            }
        }
        temp = temp->next;
    } while (temp != NULL);
    return NULL;
}

void Bucket::printRecord(int position) {
    tableData[position]->Print();
}

void Bucket::printRecords() {
 
    Bucket *temp = this;
    do {
        for (int i = 0; i < temp->numOfRecords; i++) {
            if (temp->tableData[i] != NULL) {
                temp->tableData[i]->Print();
            }
        }
        temp = temp->next;
    } while (temp != NULL);
}

bool Bucket::isBucketFull(Bucket *current) {
    if (current->numOfRecords == size) return 1;
    else return 0;
}

TableData* Bucket::getTableData(int position) {
    return tableData[position];
}