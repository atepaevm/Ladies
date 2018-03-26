#include "stdafx.h"
#include <iostream>
#include "City.h"
#include <vector>

using namespace std;


void City::setCity(string nameC, float latitudeC, float longitudeC)
{
	name = nameC;
	latitude = latitudeC;
	longitude = longitudeC;
}
