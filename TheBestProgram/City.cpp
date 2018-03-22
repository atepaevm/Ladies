#include "stdafx.h"
#include <iostream>
#include "City.h"
#include <vector>

using namespace std;

void City::addVector(City city)
{
	vectorCity.push_back(city);
}

void City::setCity(string nameC, int latitudeC, int longitudeC)
{
	name = nameC;
	latitude = latitudeC;
	longitude = longitudeC;
}
