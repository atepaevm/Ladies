#pragma once
#include <iostream>
#include <vector>

using namespace std;
class City
{
private:
	string name;
	float latitude, longitude;
public:
	void setCity(string nameC, float latitudeC, float longitudeC);
};