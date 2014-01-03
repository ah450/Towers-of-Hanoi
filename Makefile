CXXFLAG = -std=c++11 -Wall -Wextra

all: clean main
	./main

main: clean main.o rods.o
	g++ $(CXXFLAG) main.o rods.o -lGL -lglut -lGLU -o main

main.o: main.cpp include/gl.hpp include/rods.hpp
	g++ $(CXXFLAG) -c main.cpp -o main.o
rods.o: src/rods.cpp include/rods.hpp
	g++ $(CXXFLAG) -c src/rods.cpp -o rods.o
clean:
	rm -rf *o main