#pragma once
#include <iostream>
#include <vector>

using namespace std;
class City
{
public:
	/*
	City(string nameC, double latitudeC, double longitudeC) {
		this->name = nameC;
		this->latitude = latitudeC;
		this->longitude = longitudeC;
	}
	*/
	City(string nameC, double latitudeC, double longitudeC) :name(nameC), latitude(latitudeC),
		longitude(longitudeC) {};
	string name;
	double latitude, longitude;
//public:
//	void setCity(string nameC, double latitudeC, double longitudeC); //создает объект класса

};