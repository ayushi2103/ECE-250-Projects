all: openhtdriver orderedhtdriver
 
openhtdriver: openhttest.cpp openht.cpp openht.h
	g++ -std=c++11 -o  openhtdriver openhttest.cpp openht.cpp

orderedhtdriver: orderedhttest.cpp orderedht.cpp orderedht.h
	g++ -std=c++11 -o  orderedhtdriver orderedhttest.cpp orderedht.cpp

clean:
	rm openhtdriver 
	rm orderedhtdriver