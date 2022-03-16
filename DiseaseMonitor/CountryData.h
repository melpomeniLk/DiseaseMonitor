
#ifndef COUNTRYDATA_H
#define COUNTRYDATA_H

#include "TableData.h"
#include "TableDataWithTree.h"


class CountryData : public TableDataWithTree {
public:
    CountryData();
    CountryData(const CountryData& orig);
    virtual ~CountryData();
    void setData(Record*);
    virtual void Print();
    void exitPatient(string){}
private:

};

#endif /* COUNTRYDATA_H */

