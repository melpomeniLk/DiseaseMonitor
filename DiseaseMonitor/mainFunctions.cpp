#include "MainFunctions.h"
#include "appFunctions.hpp"
#include "Record.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>
#include "RecordData.h"
#include "Tree.h"

using namespace std;

void patientInput(Hash & recordHT, Hash & diseaseHT, Hash & countryHT, const char* filename) {

    ifstream file(filename);
    if (!file.good()) {
        cout << "Couldn't open the file" << endl;
    } else {
        string line;
        while (getline(file, line)) {

            if (insertPatientRecord(recordHT, diseaseHT, countryHT, line, 1) < 0) break;
          
        }
        //recordHT.printHashTable();
        //cout << "end file" << endl;
    }
}

int menu(Hash & recordHT, Hash & diseaseHT, Hash & countryHT) {
    int choice = 0;
    do {
        cout << "Write your command " << endl;
        string line;
        getline(cin, line);
        istringstream iss(line);
        string var;
        int parameters = 0;
        string command, input;
        iss >> command;
        while (iss >> var) {
            input += var + " ";
            parameters++;
        }
//        cout << command << " has ";
//        cout << parameters << endl;
//        cout << input << endl;
        choice = chooseCommand(command, parameters);
        switch (choice) {
            case 1:
                globalDiseaseStats(diseaseHT);
                break;
            case 2:
                globalDiseaseStatsBetween(diseaseHT, input);
                break;
            case 3:
                diseaseFrequency(diseaseHT, input);
                break;
            case 4:
                diseaseFrequencyCountry(diseaseHT, input);
                break;
            case 5:
                topkDiseasesForCountry(countryHT, input);
                break;
            case 6:
                topkDiseasesForCountryBetween(countryHT, input);
                break;
            case 7:
                topKCountriesForDisease(diseaseHT, input);
                break;
            case 8:
                topKCountriesForDiseaseBetween(diseaseHT, input);
                break;
            case 9:
                if (insertPatientRecord(recordHT, diseaseHT, countryHT, input, 0)>0)
                    cout << "Record added" << endl;
                break;
            case 10:
                if (insertPatientRecord(recordHT, diseaseHT, countryHT, input, 1)>0)
                    cout << "Record added" << endl;
                break;
            case 11:
                patientExit(recordHT, diseaseHT, input);
                break;
            case 12:
                numCurrentPatients(diseaseHT);
                break;
            case 13:
                numCurrentPatientsForDisease(diseaseHT, input);
                break;
            case 14: cout << "exiting" << endl;
                break;
            default: 
                cout << "Try again!" << endl;
                break;
        }
    } while (choice != 14);
    return 0;
}

int chooseCommand(string input, int p) {
    if ((input == "/globalDiseaseStats") || (input == "globalDiseaseStats")) {
        if (p == 0) return 1;
        else if (p == 2) return 2;
        else return -1;
    } else if ((input == "/diseaseFrequency") || (input == "diseaseFrequency")) {
        if (p == 3) return 3;
        else if (p == 4) return 4;
        else return -1;
    } else if ((input == "/topk-Diseases") || (input == "topk-Diseases")) {
        if (p == 2) return 5;
        else if (p == 4) return 6;
        else return -1;
    } else if ((input == "/topk-Countries") || (input == "topk-Countries")) {
        if (p == 2) return 7;
        else if (p == 4) return 8;
        else return -1;
    } else if ((input == "/insertPatientRecord") || (input == "insertPatientRecord")) {
        if (p == 6) return 9;
        else if (p == 7) return 10;
        else return -1;
    } else if ((input == "/recordPatientExit") || (input == "recordPatientExit")) {
        if (p == 2) return 11;
        else return -1;
    } else if ((input == "/numCurrentPatients") || (input == "numCurrentPatients")) {
        if (p == 0) return 12;
        else if (p == 1) return 13;
        else return -1;
    } else if ((input == "/exit") || (input == "exit")) {
        return 14;
    }
    return -1;
}