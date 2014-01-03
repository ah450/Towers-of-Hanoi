all: clean main
	./main

main: clean main.o 
	g++ main.o -lGL -lglut -lGLU -o main

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o main