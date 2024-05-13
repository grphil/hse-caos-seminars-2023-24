CXX=g++-13
CXXFLAGS=-c -Wall

main: main.o a.o
	$(CXX) main.o a.o -o main

main.o:
	$(CXX) main.cpp -o main.o $(CXXFLAGS)

a.o:
	$(CXX) a.cpp -o a.o $(CXXFLAGS)

clean:
	rm -f *.o main
