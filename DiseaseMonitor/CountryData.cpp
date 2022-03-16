#include "CountryData.h"

CountryData::CountryData() {

}

CountryData::CountryData(const CountryData& orig) {

}

CountryData::~CountryData() {

}

void CountryData::Print() {
    TableDataWithTree::Print();
}

void CountryData::setData(Record* record) {
    TableDataWithTree::setData(record);
    setKey(record->getCountry());
    setUsed(1);
}