#pragma once
#include <iostream>
#include <vector>

using namespace std;
class City
{
public:

	City(string nameC, double latitudeC, double longitudeC) :name(nameC), latitude(latitudeC),
		longitude(longitudeC) {};
	string name;
	double latitude, longitude;
};