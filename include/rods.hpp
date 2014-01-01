#pragma once

class Rods{
private:
	unsigned int length;
	float diameter;
public:
	Rods(unsigned int, double);
	void drawRods();
	void translateRods();
}