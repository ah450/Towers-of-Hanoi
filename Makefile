CXXFLAG = -std=c++11 -Wall -Wextra

all: clean main
	./main

main: clean main.o rods.o land.o disk.o texture.o
	g++ $(CXXFLAG) main.o disk.o rods.o land.o texture.o -lGL -lglut -lGLU -lpng -o main


main.o: main.cpp include/gl.hpp include/rods.hpp include/land.hpp include/texture.hpp
	g++ $(CXXFLAG) -c main.cpp -o main.o
rods.o: src/rods.cpp include/rods.hpp
	g++ $(CXXFLAG) -c src/rods.cpp -o rods.o
land.o: src/land.cpp include/land.hpp
	g++ $(CXXFLAG) -c src/land.cpp -o land.o
disk.o: src/disk.cpp
	g++ $(CXXFLAG) -c src/disk.cpp -o disk.o
texture.o: src/texture.cpp
	g++ $(CXXFLAG) -c src/texture.cpp -o texture.o

clean:
	rm -rf *o main