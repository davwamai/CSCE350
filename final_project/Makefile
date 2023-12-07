CXX = g++
CXXFLAGS = -Wall -std=c++11

all: Wamai_David_Quicksort InputFileGenerator

Wamai_David_Quicksort: Wamai_David_Quicksort.o
	$(CXX) $(CXXFLAGS) -o Wamai_David_Quicksort Wamai_David_Quicksort.o

InputFileGenerator: InputFileGenerator.o
	$(CXX) $(CXXFLAGS) -o InputFileGenerator InputFileGenerator.o

Wamai_David_Quicksort.o: Wamai_David_Quicksort.cpp
	$(CXX) $(CXXFLAGS) -c Wamai_David_Quicksort.cpp

InputFileGenerator.o: InputFileGenerator.cpp
	$(CXX) $(CXXFLAGS) -c InputFileGenerator.cpp

clean:
	rm -f *.o Wamai_David_Quicksort InputFileGenerator

