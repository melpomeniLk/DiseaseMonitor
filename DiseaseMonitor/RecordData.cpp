#include "RecordData.h"

RecordData::RecordData(){
    record = NULL;
}

//RecordData::RecordData(Record * record) : record(record) {
//
//}

RecordData::~RecordData() {
    if (record != NULL) {
        delete record;
    }
}

void RecordData::setData(Record * info){
    //cout << "RecordData setting data " << endl;
    if (record != NULL) {
        delete record;
    }
    record = info;
    setKey(info->getRecordID());
}

void RecordData::exitPatient(string date){
    record->setExitDate(date);
    //cout << date << endl;
}

void RecordData::Print() {
    record->Print();
}
