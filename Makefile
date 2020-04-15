CC=g++
CFLAGS=-std=c++17 -Wall -Werror -Wextra -pedantic -g
LDLIBS=-lstdc++fs
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
BINARY_NAME=cshell


.PHONY: all clean

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf *.o $(BINARY_NAME)
