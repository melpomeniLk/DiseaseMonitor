#include <iostream>
#include <string.h>
#include "MainFunctions.h"
#include "DataType.h"
#include "Hash.hpp"
#include "appFunctions.hpp"
#include "Date.hpp"
#include "Tree.h"
#include "Heap.h"

using namespace std;

// "${OUTPUT_PATH}" -p large.txt -h1 100 -h2 100 -b 4096

int main(int argc, char** argv) {

    const char *patientFile;
    int diseaseHTsize, countryHTsize;
    int bucketSize;

    if (argc == 9) {
        for (int i = 1; i < argc; i += 2) {
            if (strcmp(argv[i], "-p") == 0) patientFile = argv[i + 1];
            else if (strcmp(argv[i], "-h1") == 0) diseaseHTsize = atoi(argv[i + 1]);
            else if (strcmp(argv[i], "-h2") == 0) countryHTsize = atoi(argv[i + 1]);
            else if (strcmp(argv[i], "-b") == 0) bucketSize = atoi(argv[i + 1]);
        }

//         cout << "The file is: " << patientFile << endl << "the size of DiseaseHT is " << diseaseHTsize << endl;
//         cout << "the size of CountryHT is " << countryHTsize << endl << "and bucket size " << bucketSize << endl;
        

       Hash recordHT(TYPE_RECORD, countryHTsize, bucketSize);
       Hash diseaseHT(TYPE_DISEASE, diseaseHTsize, bucketSize);
       Hash countryHT(TYPE_COUNTRY, countryHTsize, bucketSize);

       patientInput(recordHT, diseaseHT, countryHT, patientFile);

       menu(recordHT, diseaseHT, countryHT);

    } else cout << "I need more arguments" << endl;

    return 0;
}