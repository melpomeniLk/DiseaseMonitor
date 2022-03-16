#include "Record.h"

Record::Record(){
    
}

Record::Record(string id, string name, string last, string disease, 
        string country, Date entry, Date exit) : recordID(id), name(name), 
        lastName(last), diseaseID(disease), country(country) {
     entryDate.copyDate(entry);
     exitDate.copyDate(exit);
}



Record::~Record() {

}

void Record::Print() {
    cout << recordID << " " << name << " " << lastName << " " << diseaseID;
    cout << " " << country << " " ;
    entryDate.printDate();
    cout << " ";
    exitDate.printDate();
    cout << endl;
}