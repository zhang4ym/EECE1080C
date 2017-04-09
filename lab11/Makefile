CC=g++
CFLAGS=-c -Wall -ggdb -I.
LDFLAGS=
SOURCES=list-sandbox.cpp
EXECUTABLE=list-sandbox
TESTS=LList_test.h LListR_test.h

OBJECTS=$(SOURCES:.cpp=.o)


FLAGS   = -Iinclude

all: $(SOURCES) $(EXECUTABLE)
	

# These next lines do a bit of magic found from http://stackoverflow.com/questions/2394609/makefile-header-dependencies
# Essentially it asks the compiler to read the .cpp files and generate the needed .h dependencies.
# This way if any .h file changes the correct .cpp files will be recompiled
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ >> ./.depend;

include .depend
# End .h file magic

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
	rm -f ./.depend
	rm -f testrunner*
	rm -f Result*
	rm -f speed
	
# CXX Testing	
CXXLOCATION = ../cxxtest
CXXTESTGEN = $(CXXLOCATION)/bin/cxxtestgen

test: testrunner
	./testrunner

testrunner: testrunner.cpp
	g++ -I. -I$(CXXLOCATION)/ -ggdb -Wall -o testrunner testrunner.cpp 
	

testrunner.cpp: $(HEADERS) $(SOURCES) $(TESTS) depend
	$(CXXTESTGEN) --error-printer -o testrunner.cpp $(TESTS) 
	
	
speed: speede FORCE
	./speed 0 > ResultPushBack.txt
	./speed 1 > ResultpushFront.txt
	./speed 2 > ResultPopBack.txt
	./speed 3 > ResultPopFront.txt
	./speed 4 > Resultsize.txt
	./speed 5 > Resultaccess.txt
	gnuplot toplot.txt
	
speede: LListR.h LListR_test.h speed.cpp
	g++ -I. -ggdb -Wall -O2 speed.cpp -o speed
	
FORCE:


