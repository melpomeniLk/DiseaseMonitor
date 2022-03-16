#ifndef MAINFUNC_H
#define MAINFUNC_H
#include <fstream>
#include <iostream>
#include "Hash.hpp"
using namespace std;

//void patientInput(const char*);
void patientInput(Hash & , Hash & , Hash & , const char *);
int menu(Hash & recordHT, Hash & diseaseHT, Hash & countrHT);
int chooseCommand(string, int);

#endif /* MAINFUNC_H */

