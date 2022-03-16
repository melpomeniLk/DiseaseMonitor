#ifndef menu_hpp
#define menu_hpp

#include "Hash.hpp"
#include <string>
#include <iostream>

using namespace std;

int globalDiseaseStats(Hash &);
int globalDiseaseStatsBetween(Hash &,string);
int diseaseFrequency(Hash &,string);
int diseaseFrequencyCountry(Hash &,string);
int topkDiseasesForCountry(Hash &,string);
int topkDiseasesForCountryBetween(Hash &,string);
int topKCountriesForDisease(Hash &,string);
int topKCountriesForDiseaseBetween(Hash &,string);
int insertPatientRecord(Hash &,Hash &,Hash &,string,bool);
int patientExit(Hash &,Hash &,string);
int numCurrentPatients(Hash &);
int numCurrentPatientsForDisease(Hash &,string);
int exit();

#endif
