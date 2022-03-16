#ifndef RECORDDATA_H
#define RECORDDATA_H
#include "Record.h"
#include "TableData.h"

class RecordData : public TableData {
public:
    RecordData();
    RecordData(Record record);
    virtual ~RecordData();

    void setData(Record*);
    virtual void Print();
    virtual void exitPatient(string date);
    void addCase() {}

    Record* getRecord() const {
        return record;
    }

    void setRecord(Record* record) {
        this->record = record;
    }

private:
    Record *record;
};

#endif /* RECORDDATA_H */

