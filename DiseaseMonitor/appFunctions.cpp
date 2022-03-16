#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "appFunctions.hpp"
#include "DataType.h"
#include "CountryData.h"
#include "DiseaseData.h"
#include "TableData.h"
#include "RecordData.h"

using namespace std;

int insertPatientRecord(Hash &recordHT, Hash & diseaseHT, Hash & countryHT, string input, bool hasDischarge) {
    //cout << "i will insert this " << input << endl;
    stringstream line(input);

    string id, name, last, disease, country, entry, exit;

    getline(line, id, ' ');
    getline(line, name, ' ');
    getline(line, last, ' ');
    getline(line, disease, ' ');
    getline(line, country, ' ');
    getline(line, entry, ' ');

    //cout << id << endl;
    
    Date d1, d2;
    d1.setDate(entry);
    if (d1.isEmpty()) {
        cout << "error";
        d1.printDate();
        //cout << endl << "for id " << id << endl;
        return 0;
    }
    if (hasDischarge) getline(line, exit, ' ');
    else exit = "-";



    d2.setDate(exit);
    if (!d2.isEmpty()) {
        if (d1.compareDate(d2) > 0) {
            cout << "error";
//            d1.printDate();
//            cout << endl;
//            d2.printDate();
//            cout << endl << "for id " << id << endl;
            return 0;
        }
    }

    Record * record = new Record(id, name, last, disease, country, entry, exit);
    if (!recordHT.putItemOnHashTable(record)) {
        cout << "error" << endl;
        delete record;
        return -1;
    } else {
        diseaseHT.putItemOnHashTable(record);
        countryHT.putItemOnHashTable(record);
    }

    return 1;
}

int patientExit(Hash &recordHT, Hash &diseaseHT, string input) {
    stringstream check1(input);
    string id, date;
    getline(check1, id, ' ');
    getline(check1, date, ' ');
    // cout << "exit date is " << date << endl;
    // cout << "id is " << id << endl;

    RecordData * data = (RecordData*) recordHT.findItemOnHashTable(id);
    if (data == NULL) {
        cout << "Not found" << endl;
    } else {
        Record *record = data->getRecord();
        // if (record->hasDischarge()) {
        //     cout << "error" << endl;
        //     return -1;
        // } else {
            string id = record->getDiseaseID();
            Date entry,exit;
            exit.setDate(date);
            entry.copyDate(record->getEntryDate());
//            entry.printDate(); cout << endl;
//            exit.printDate(); cout << endl;
            if (entry.compareDate(exit) < 0 || entry.compareDate(exit) == 0){
                DiseaseData * disease = (DiseaseData*) diseaseHT.findItemOnHashTable(id);
                data->exitPatient(date);
                disease->exitPatient(date);
                cout << "Record updated" << endl;
            }else cout << "error" << endl;
    }

    return 0;
}

int globalDiseaseStats(Hash &diseaseHT) {
    diseaseHT.printHashTable();
    return 0;
}

int globalDiseaseStatsBetween(Hash &diseaseHT, string input) {
    stringstream check1(input);
    string d1, d2;
    getline(check1, d1, ' ');
    getline(check1, d2, ' ');
    Date date1, date2;
    date1.setDate(d1);
    date2.setDate(d2);
    if (date1.compareDate(date2) < 0) {
        diseaseHT.globalDisease(date1, date2);
    }
    return 0;
}

int numCurrentPatients(Hash &diseaseHT) {
    diseaseHT.printPatients();
    return 0;
}

int diseaseFrequency(Hash & diseaseHT, string input) {
    stringstream check1(input);
    string disease, d1, d2;
    getline(check1, disease, ' ');
    getline(check1, d1, ' ');
    getline(check1, d2, ' ');

    DiseaseData * diseaseData = (DiseaseData*) diseaseHT.findItemOnHashTable(disease);

    if (diseaseData != NULL) {
        Tree * tree = diseaseData->getTree();
        Date date1, date2;
        //tree->printTree();
        date1.setDate(d1);
        date2.setDate(d2);
        int n = tree->frequency(date1, date2);

        cout << disease << " " << n << endl;
    }
    return 0;
}

int diseaseFrequencyCountry(Hash &diseaseHT, string input) {
    stringstream check1(input);
    string disease, country, d1, d2;
    getline(check1, disease, ' ');
    getline(check1, d1, ' ');
    getline(check1, d2, ' ');
    getline(check1, country, ' ');


    DiseaseData * diseaseData = (DiseaseData*) diseaseHT.findItemOnHashTable(disease);

    if (diseaseData != NULL) {
        Tree * tree = diseaseData->getTree();
        Date date1, date2;
        date1.setDate(d1);
        date2.setDate(d2);
        int n = tree->frequencyCountry(country, date1, date2);

        cout << disease << " " << n << endl;
    }
    return 0;


}

int numCurrentPatientsForDisease(Hash &diseaseHT, string input) {
    stringstream check1(input);
    string key;
    getline(check1, key, ' ');
    DiseaseData * disease = (DiseaseData*) diseaseHT.findItemOnHashTable(key);
    if (disease != NULL) {
        cout << key << " " << disease->getPatients() << endl;
    }else{
        cout << key << " 0" << endl;
    }
    return 0;
}

int topkDiseasesForCountry(Hash &countryHT, string input) {
    stringstream check1(input);
    string k, key;
    getline(check1, k, ' ');
    getline(check1, key, ' ');
    CountryData * country = (CountryData*) countryHT.findItemOnHashTable(key);
    if (country != NULL) {
        Tree * tree = country->getTree();
        tree->topK_diseases(stoi(k),key);
    }
    return 0;
}

int topkDiseasesForCountryBetween(Hash &countryHT, string input) {
    stringstream check1(input);
    string k, key, d1, d2;
    getline(check1, k, ' ');
    getline(check1, key, ' ');
    getline(check1, d1, ' ');
    getline(check1, d2, ' ');
    Date date1, date2;
    date1.setDate(d1);
    date2.setDate(d2);
    CountryData * country = (CountryData*) countryHT.findItemOnHashTable(key);
    if (country != NULL) {
        Tree * tree = country->getTree();
        tree->topK_diseasesBetween(stoi(k),key,date1,date2);
    }
    return 0;
}

int topKCountriesForDisease(Hash &diseaseHT, string input) {
    stringstream check1(input);
    string k, key;
    getline(check1, k, ' ');
    getline(check1, key, ' ');
    DiseaseData * disease = (DiseaseData*) diseaseHT.findItemOnHashTable(key);
    if (disease != NULL) {
        Tree * tree = disease->getTree();
        tree->topK_Countries(stoi(k),key);
    }
    return 0;
}

int topKCountriesForDiseaseBetween(Hash &diseaseHT, string input) {
    stringstream check1(input);
    string k, key, d1, d2;
    getline(check1, k, ' ');
    getline(check1, key, ' ');
    getline(check1, d1, ' ');
    getline(check1, d2, ' ');
    Date date1, date2;
    date1.setDate(d1);
    date2.setDate(d2);
    DiseaseData * disease = (DiseaseData*) diseaseHT.findItemOnHashTable(key);
    if (disease != NULL) {
        Tree * tree = disease->getTree();
        tree->topK_CountriesBetween(stoi(k),key,date1,date2);
    }
    return 0;
}
