
CXX=g++
CFLAGS=-c

Personnage.o: Personnage.cpp
	$(CXX) $(CFLAGS) Personnage.cpp -o Personnage.o	

template.o: template.cpp
	$(CXX) $(CFLAGS) template.cpp -o template.o

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o 

hello: main.o Personnage.o template.o
	$(CXX) -o hello Personnage.o template.o main.o

all: hello

clean:
	rm *.o