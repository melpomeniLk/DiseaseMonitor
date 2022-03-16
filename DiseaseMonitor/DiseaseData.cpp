#include "DiseaseData.h"

DiseaseData::DiseaseData() {
    patients = 0 ;
}

DiseaseData::DiseaseData(const DiseaseData& orig) {

}

DiseaseData::~DiseaseData() {

}

void DiseaseData::Print() {
    TableDataWithTree::Print();
}

void DiseaseData::PrintPatients(){
    cout << TableData::getKey() << " "<<  patients << endl;
}

void DiseaseData::setData(Record *record) {
   TableDataWithTree::setData(record);
   setKey(record->getDiseaseID());
   setUsed(1);
   //cout << "exit date is " << record->getExitDate() << endl;
   if(!record->hasDischarge()) addPatient();
}

void DiseaseData::addPatient(){
    patients++;
}