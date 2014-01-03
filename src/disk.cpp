#include "../include/disk.hpp"
#include <cstring>


constexpr int height = 1;
constexpr int stacks = 30;

Disk::Disk(Point origin, Color rgba ,double in_radius, double out_radius): quad(gluNewQuadric()){
	disk_origin = origin;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->slices = 200;
	this->loops = 200;
	gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
	std::memcpy(this->rgba, reinterpret_cast<const void *>(&rgba), 4 * sizeof(float));
}

Disk::Disk(Point origin, Color rgba, double in_radius, double out_radius, int slices, int loops): quad(gluNewQuadric()){
	disk_origin = origin;
	this->in_radius = in_radius;
	this->out_radius = out_radius;
	this->slices = slices;
	this->loops = loops;
	gluQuadricDrawStyle(quad, GLU_FILL);
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluQuadricOrientation(quad, GLU_OUTSIDE);
	std::memcpy(this->rgba, reinterpret_cast<const void *>(&rgba), 4 * sizeof(float));
}

void Disk::construct_disk(){
	glPushMatrix();
		glTranslatef(0,height,0);
		glRotatef(-90,1,0,0);
		gluDisk(quad, in_radius, out_radius, slices, loops);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-90,1,0,0);
	    gluCylinder(quad, in_radius, in_radius,  height, slices, stacks);
	    gluCylinder(quad, out_radius, out_radius,  height, slices, stacks);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-90,1,0,0);
		gluDisk(quad, in_radius, out_radius, slices, loops);
	glPopMatrix();
}

void Disk::draw(){
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	    glTranslatef(disk_origin.x, disk_origin.y - (in_radius) , disk_origin.z);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, rgba);
		construct_disk();
	glPopMatrix();
}

void Disk::move(const vector& v){
	disk_origin.x += v.x;
	disk_origin.y += v.y;
	disk_origin.z += v.z;
}

Point Disk::get_origin(){
	return disk_origin;
}

void Disk::set_origin(Point p){
	disk_origin.x = p.x;
	disk_origin.y = p.y;
	disk_origin.z = p.z;
}

