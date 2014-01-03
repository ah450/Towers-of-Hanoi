all: clean main
	./main

main: clean disk.o main.o 
	g++ disk.o main.o -lGL -lglut -lGLU -o main

main.o: main.cpp
	g++ -c main.cpp

disk.o: src/disk.cpp
	g++ -c src/disk.cpp

clean:
	rm -rf *o main