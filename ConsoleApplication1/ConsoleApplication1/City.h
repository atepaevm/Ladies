#pragma once
#include <iostream>
#include <vector>

using namespace std;
class City
{
public:
	string name;
	double latitude, longitude;
public:
	void setCity(string nameC, double latitudeC, double longitudeC); //создает объект класса
};