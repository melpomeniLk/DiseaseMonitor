# Disease Monitor

This project has been implemented for the course of Systems Programming (2020) in Department of Informatics and Telecommunications at University of Athens, Greece.

The application receives, processes and answers queries about disease cases.

There are two input files that includes data for disease cases  (small.txt and large.txt).

After the execution you can write your command according to print-format.txt (the file includes all the commands and the expected output).

# Compile - Run

The project includes makefile so in order to compile please run:

./make
    
For execution you can choose one command from the following: 
1. ./make run (you can adjust the parameters in makefile) 
2. ./diseaseMonitor -p (inputfile) -h1 (diseaseHashTableSize) -h2 (CountryHashTableSize) -b (bucketSize)
