# Makefile

CXX_FLAG = --std=c++11 -g

all: game testcards

game:: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

main.o: main.cpp
	g++ -c $(CXX_FLAG) main.cpp

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f game testcards *.o