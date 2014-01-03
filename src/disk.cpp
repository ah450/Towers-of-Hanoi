#include "../include/disk.hpp"

Disk::Disk(Point origin ,double in_radius, double out_radius){
	disk_origin = origin;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->nsides = 100;
	this->rings = 100;
}

Disk::Disk(Point origin ,double in_radius, double out_radius, double nsides, double rings){
	disk_origin = origin;
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

void Disk::moveDisk(){
}
