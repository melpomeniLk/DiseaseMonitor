OBJS	= appFunctions.o Bucket.o CountryData.o Date.o DiseaseData.o Hash.o Heap.o main.o mainFunctions.o Record.o RecordData.o RecordLL.o TableData.o TableDataWithTree.o Tree.o
SOURCE	= appFunctions.cpp Bucket.cpp CountryData.cpp Date.cpp DiseaseData.cpp Hash.cpp Heap.cpp main.cpp mainFunctions.cpp Record.cpp RecordData.cpp RecordLL.cpp TableData.cpp TableDataWithTree.cpp Tree.cpp
HEADER	= 
OUT	= diseaseMonitor
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

appFunctions.o: appFunctions.cpp
	$(CC) $(FLAGS) appFunctions.cpp -std=c++11

Bucket.o: Bucket.cpp
	$(CC) $(FLAGS) Bucket.cpp -std=c++11

CountryData.o: CountryData.cpp
	$(CC) $(FLAGS) CountryData.cpp -std=c++11

Date.o: Date.cpp
	$(CC) $(FLAGS) Date.cpp -std=c++11

DiseaseData.o: DiseaseData.cpp
	$(CC) $(FLAGS) DiseaseData.cpp -std=c++11

Hash.o: Hash.cpp
	$(CC) $(FLAGS) Hash.cpp -std=c++11

Heap.o: Heap.cpp
	$(CC) $(FLAGS) Heap.cpp -std=c++11

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

mainFunctions.o: mainFunctions.cpp
	$(CC) $(FLAGS) mainFunctions.cpp -std=c++11

Record.o: Record.cpp
	$(CC) $(FLAGS) Record.cpp -std=c++11

RecordData.o: RecordData.cpp
	$(CC) $(FLAGS) RecordData.cpp -std=c++11

RecordLL.o: RecordLL.cpp
	$(CC) $(FLAGS) RecordLL.cpp -std=c++11

TableData.o: TableData.cpp
	$(CC) $(FLAGS) TableData.cpp -std=c++11

TableDataWithTree.o: TableDataWithTree.cpp
	$(CC) $(FLAGS) TableDataWithTree.cpp -std=c++11

Tree.o: Tree.cpp
	$(CC) $(FLAGS) Tree.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)

run:
	./diseaseMonitor -p small.txt -h1 100 -h2 100 -b 512

