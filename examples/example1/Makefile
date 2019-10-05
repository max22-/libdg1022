all: example1
.PHONY: clean

example1.o: main.cpp
	g++ -c main.cpp -I../../include -Wall -o example1.o

example1: example1.o
	g++ example1.o -Wl,-rpath=../../lib/ -L../../lib -ldg1022 -o example1

clean:
	rm -f example1
	rm -f *.o
