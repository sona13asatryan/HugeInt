all : main.cpp HugeInt.o
	g++ -g -o  main HugeInt.o main.cpp

HugeInt.o : HugeInt.cpp HugeInt.h
	g++ -g -c HugeInt.cpp

clean: rm *.o main

.PHONY: all clean