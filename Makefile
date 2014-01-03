CXXFLAG = -std=c++11 -Wall -Wextra

all: clean main
	./main

main: clean main.o rods.o land.o disk.o utility.o
	g++ $(CXXFLAG) main.o disk.o rods.o land.o utility.o bitmap.o -lGL -lglut -lGLU -o main


main.o: main.cpp include/gl.hpp include/rods.hpp include/land.hpp
	g++ $(CXXFLAG) -c main.cpp -o main.o
rods.o: src/rods.cpp include/rods.hpp
	g++ $(CXXFLAG) -c src/rods.cpp -o rods.o
land.o: src/land.cpp include/land.hpp utility.o
	g++ $(CXXFLAG) -c src/land.cpp -o land.o
disk.o: src/disk.cpp utility.o
	g++ $(CXXFLAG) -c src/disk.cpp -o disk.o
utility.o: src/utility.cpp bitmap.o
	g++ $(CXXFLAG) -c src/utility.cpp -o utility.o
bitmap.o: src/bitmap.cpp
	g++ $(CXXFLAG) -c src/bitmap.cpp -o bitmap.o
clean:
	rm -rf *o main