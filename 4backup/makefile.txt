CXX = -g -ansi -pedantic -Wall -Wextra -Werror -std=c++14

main: main.cpp rv32i.cpp memory.cpp hex.cpp
	$(CXX) $(CPPFLAGS) -c -o main.o main.cpp
	$(CXX) $(CPPFLAGS) -c -o rv32i.o rv32i.cpp
	$(CXX) $(CPPFLAGS) -c -o memory.o memory.cpp
	$(CXX) $(CPPFLAGS) -c -o hex.o hex.cpp
	$(CXX) $(CPPFLAGS) -o rv32i main.o rv32i.o memory.o hex.o

clean:
	rm -f *.o main