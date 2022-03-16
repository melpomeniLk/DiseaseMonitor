
#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <iostream>
#include "Date.hpp"

using namespace std;

class Record {
public:
    Record();
    Record(string, string, string, string, string, Date, Date);
    virtual ~Record();
    
    Record(Record& other) :
    recordID(other.recordID), name(other.name), lastName(other.lastName), diseaseID(other.diseaseID), country(other.country), entryDate(other.entryDate), exitDate(other.exitDate) {
    }

    
    string getCountry() {
        return country;
    }

    void setCountry(string country) {
        this->country = country;
    }

    string getDiseaseID() {
        return diseaseID;
    }

    void setDiseaseID(string diseaseID) {
        this->diseaseID = diseaseID;
    }

    Date getEntryDate() const {
        return entryDate;
    }

    void setEntryDate(string entry) {
        this->entryDate.setDate(entry);
    }

    Date getExitDate() const {
        return exitDate;
    }

    void setExitDate(string exit) {
        exitDate.setDate(exit);
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(string lastName) {
        this->lastName = lastName;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getRecordID()  {
        return recordID;
    }

    void setRecordID(string recordID) {
        this->recordID = recordID;
    }

    void Print();
    
    bool hasDischarge(){ return (!exitDate.isEmpty());}
    
private:
    string recordID;
    string name;
    string lastName;
    string diseaseID;
    string country;
    Date entryDate;
    Date exitDate;
};

#endif /* RECORD_H */

