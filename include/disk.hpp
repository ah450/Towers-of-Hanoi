#pragma once

class Disk{
private:
	unsigned int id;
	float height;
	float inner_diameter;
	float outer_diameter;
public:
	Disk(float, float, float);
	void drawDisk();
	void translateDisk();//fix me
}