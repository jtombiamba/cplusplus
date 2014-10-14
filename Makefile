
CXX=g++
CFLAGS=-c

template.o: template.cpp
	$(CXX) $(CFLAGS) template.cpp -o template.o

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o 

hello: main.o template.o
	$(CXX) -o hello template.o main.o

all: hello

clean:
	rm *.o