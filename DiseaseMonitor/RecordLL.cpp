#include "RecordLL.hpp"

RecordLL::RecordLL() {
    head = NULL;
    tail = NULL;
    numOfNodes = 0;
}

RecordLL::~RecordLL() {
    ListNode *temp;
    temp = head;
    while (temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void RecordLL::InsertNode(Record *data) {
    if (head == NULL) {
        head = new ListNode();
        head->record = data;
        tail = head;
        numOfNodes++;
    } else {
        if (tail->next == NULL) {
            tail->next = new ListNode();
            tail = tail->next;
            tail->record = data;
            tail->next = NULL;
            numOfNodes++;
        }
    }
}

int RecordLL::FindNode(string key) {
    int counter = 0;
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        ListNode *temp;
        temp = head;
        while (temp != NULL) {
            if ((temp->record->getCountry()) == key) {
                counter++;
                //cout << temp->record->getRecordID() << " " << temp->record->getCountry() << endl;
            }
            temp = temp->next;
        }
    }
    return counter;
}

void RecordLL::printNode(string key) {

}

void RecordLL::PrintList() {
    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        ListNode *temp;
        temp = head;
        while (temp != NULL) {
            temp->record->Print();
            temp = temp->next;
        }
    }
}

int RecordLL::getNumOfNodes() {
    return numOfNodes;
}

bool RecordLL::isListEmpty() {
    if (numOfNodes == 0) return 0;
    else return 1;
}