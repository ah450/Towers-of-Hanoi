CXXFLAG = -std=c++11 -Wall -Wextra -g
OBJECTS = main.o rods.o land.o disk.o texture.o
LIBS = -lGL -lglut -lGLU -lpng
CXX = clang++
all: clean main
	./main

main: clean $(OBJECTS)
	$(CXX) $(CXXFLAG) $(OBJECTS) $(LIBS) -o main


main.o: main.cpp include/gl.hpp include/rods.hpp include/land.hpp
	$(CXX) $(CXXFLAG) -c main.cpp -o main.o
rods.o: src/rods.cpp include/rods.hpp
	$(CXX) $(CXXFLAG) -c src/rods.cpp -o rods.o
land.o: src/land.cpp include/land.hpp texture.o
	$(CXX) $(CXXFLAG) -c src/land.cpp -o land.o
disk.o: src/disk.cpp texture.o
	$(CXX) $(CXXFLAG) -c src/disk.cpp -o disk.o
texture.o: src/texture.cpp
	$(CXX) $(CXXFLAG) -c src/texture.cpp -o texture.o

clean:
	rm -rf *o main