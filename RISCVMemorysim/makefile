# Giovanni Moscato 
#

# Variables
# -ansi: implement ANSI language option, turning off ceritan features that are incompatible 
# -pedantic: used with ANSI , adhere strictly to ANSI standards , rejecting non-compliant code
CXXFLAGS = -ansi -pedantic -Wall -Wextra -g -std=c++11

memory: main.o memory.o hex.o
	g++ $(CXXFLAGS) -o memory main.o memory.o hex.o

main.o: main.cpp hex.h memory.h
	g++ $(CXXFLAGS) -c main.cpp

hex.o: hex.cpp hex.h
	g++ $(CXXFLAGS) -c hex.cpp

memory.o: memory.cpp memory.h
	g++ $(CXXFLAGS) -c memory.cpp

clean:
	-rm *.o main
