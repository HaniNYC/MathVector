CC=g++
CFLAGS=-c

all: testVector.o VecXd.o 
	$(CC) testVector.o VecXd.o  -o run

testVector.o: testVector.cpp VecXd.h
	$(CC) $(CFLAGS) testVector.cpp

VecXd.o: VecXd.cpp VecXd.h
	$(CC) $(CFLAGS) VecXd.cpp


clean:
	rm -f*.o all
