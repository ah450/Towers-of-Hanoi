#include "../include/disk.hpp"

Disk::Disk(double in_radius, double out_radius){
	static counter = 0;
	counter ++:
	this->id = counter;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->nsides = 20;
	this->rings = 20;
}

Disk::Disk(double in_radius, double out_radius, double nsides, double rings){
	static counter = 0;
	counter ++:
	this->id = counter;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->nsides = nsides;
	this->rings = rings;
}

void Disk::drawDisk(){
	glPushMatrix();
		glutSolidTorus(in_radius, out_radius, nsides, rings);
	glPopMatrix();
}

void Disk::translateDisk(){
}
