CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=myBank.o
FLAGS= -Wall -g

all: mybanks mains	
mains: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a 
mybanks: libmyBank.a
libmyBank.a: $(OBJECTS_LIB) myBank.h
	$(AR) -rcs libmyBank.a $(OBJECTS_LIB)
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c -fPIC myBank.c
main.o: main.c myBank.c myBank.h 
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all myBanks

clean:
	rm -f *.o *.a mains
