#pragma once

class Disk{
private:
	unsigned int id;
	double in_radius;
	double out_radius;
    double nsides;
    double rings;
public:
	Disk(double, double);
    Disk(double, double, double, double);
	void drawDisk();
	void translateDisk();//fix me
};