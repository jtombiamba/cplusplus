
CXX=g++
CFLAGS=-c -g

Personnage.o: Personnage.cpp
	$(CXX) $(CFLAGS) Personnage.cpp -o Personnage.o	

ZFraction.o: ZFraction.cpp
	$(CXX) $(CFLAGS) ZFraction.cpp -o ZFraction.o	


template.o: template.cpp
	$(CXX) $(CFLAGS) template.cpp -o template.o

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp -o main.o 

hello: main.o Personnage.o ZFraction.o template.o
	$(CXX) -o hello Personnage.o ZFraction.o template.o main.o

all: hello

clean:
	rm *.o