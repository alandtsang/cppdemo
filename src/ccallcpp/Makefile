CC  ?= gcc
CXX ?= g++

CFLAGS = -O0 -g -Wall
CXXFLAGS = -O0 -g -Wall

OBJ  = main person wrapper
OBJS = $(addsuffix .o,$(OBJ))

all:
	make compile

compile:
	make $(OBJS)
	make test
 
test: $(OBJS) 
	$(CXX) -o test $(OBJS)
 
main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c
 
person.o: person.cpp
	$(CXX) $(CXXFLAGS) -c -o person.o person.cpp

wrapper.o: wrapper.cpp
	$(CXX) $(CXXFLAGS) -c -o wrapper.o wrapper.cpp
 
clean:
	@ rm -rf $(OBJS) test *.o *.a
