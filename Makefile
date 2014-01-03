CXXFLAG = -std=c++11 -Wall -Wextra
COMPILER = clang++
all: clean main
	./main

main: clean main.o rods.o land.o disk.o environment.o
	${COMPILER} $(CXXFLAG) environment.o main.o disk.o rods.o land.o -lGL -lglut -lGLU -o main
main.o: main.cpp include/gl.hpp include/rods.hpp include/land.hpp
	${COMPILER} $(CXXFLAG) -c main.cpp -o main.o
rods.o: src/rods.cpp include/rods.hpp
	${COMPILER} $(CXXFLAG) -c src/rods.cpp -o rods.o
land.o: src/land.cpp include/land.hpp
	${COMPILER} $(CXXFLAG) -c src/land.cpp -o land.o
disk.o: src/disk.cpp
	${COMPILER} $(CXXFLAG) -c src/disk.cpp -o disk.o
environment.o:
	${COMPILER} $(CXXFLAG) -c src/environment.cpp -o environment.o

clean:
	rm -rf *o main