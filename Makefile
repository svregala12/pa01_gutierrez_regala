# Makefile

CXX_FLAG = --std=c++11 -g

all: game testcards

game:: main.o cards.o
	g++ $(CXX_FLAG) -o game main.o cards.o

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards main.o testcards.o cards.o

clean:
	rm -f game testcards *.o

