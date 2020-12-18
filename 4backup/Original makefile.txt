# Giovanni Moscato 
#

# Variables
# -ansi: implement ANSI language option, turning off ceritan features that are incompatible 
# -pedantic: used with ANSI , adhere strictly to ANSI standards , rejecting non-compliant code
CXXFLAGS = -ansi -pedantic -Wall -Wextra -g -std=c++14


rv32i: main.o memory.o hex.o rv32i.o registerfile.o
    g++ $(CXXFLAGS) -o rv32i main.o memory.o hex.o rv32i.o registerfile.o


main.o: main.cpp hex.h memory.h rv32i.h registerfile.h
    g++ $(CXXFLAGS) -c main.cpp

hex.o: hex.cpp hex.h
    g++ $(CXXFLAGS) -c hex.cpp

memory.o: memory.cpp memory.h
    g++ $(CXXFLAGS) -c memory.cpp

rv32i.o: rv32i.cpp rv32i.h
    g++ $(CXXFLAGS) -c rv32i.cpp

registerfile.o: registerfile.cpp registerfile.h
    g++ $(CXXFLAGS) -c registerfile.cpp


clean:
    -rm *.o rv32i
