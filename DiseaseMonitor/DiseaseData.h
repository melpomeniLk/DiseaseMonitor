#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include "TableData.h"
#include "TableDataWithTree.h"


class DiseaseData : public TableDataWithTree {
public:
    DiseaseData();
    DiseaseData(const DiseaseData& orig);
    virtual ~DiseaseData();
    void setData(Record*);
    virtual void Print();
    void PrintPatients();
    void exitPatient(string){patients--;}
    void addPatient();

    int getPatients() const {
        return patients;
    }

private:
    int patients;
};

#endif /* DISEASEDATA_H */

