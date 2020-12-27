#pragma once
#include <iostream>
using namespace std;

class vecThreeD
{
private:
	float a;
	float b;
	float c;
public:
	vecThreeD();
	void display();
	void enter(float ent1, float ent2, float ent3);
	double azimuth();
	int compare(float cmp1, float cmp2, float cmp3);
};