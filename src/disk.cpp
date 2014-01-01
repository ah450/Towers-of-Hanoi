#include "./include/Disk.hpp"

Disk::Disk(float height, float inner_diameter, float outer_diameter){
	static counter = 0;
	counter ++:
	this->id = counter;
	this->inner_diameter = inner_diameter;
	this->outer_diameter = outer_diameter;
	this->vertSlices = vertSlices;
	this->horizSlices = horizSlices;
}

void Disk::drawDisk(){
	glPushMatrix();
		GLUquadric* disk;
		quadric = gluNewQuadric();
		gluDisk(disk, inner_diameter, outer_diameter, vertSlices, horizSlices);
	glPopMatrix();
}

void Disk::translateDisk(){

}