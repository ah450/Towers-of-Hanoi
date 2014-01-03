#include "../include/disk.hpp"
#include <cstring>

Disk::Disk(Point origin, Color rgba ,double in_radius, double out_radius){
	disk_origin = origin;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->nsides = 100;
	this->rings = 100;
	std::memcpy(this->rgba, reinterpret_cast<const void *>(&rgba), 4 * sizeof(float));
}

Disk::Disk(Point origin, Color rgba, double in_radius, double out_radius, double nsides, double rings){
	disk_origin = origin;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->nsides = nsides;
	this->rings = rings;
	std::memcpy(this->rgba, reinterpret_cast<const void *>(&rgba), 4 * sizeof(float));
}

void Disk::draw(){
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba);
		glRotatef(90, 1,0,0);
		glScalef(0.5,0.5,0.5);
		glutSolidTorus(in_radius, out_radius, nsides, rings);
	glPopMatrix();
}

void Disk::move(){
}
