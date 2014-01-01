all: clean Main
	./Main

Main: clean Main.o 
	g++ Main.o -framework OpenGL -framework GLUT -o Main

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf *o Main