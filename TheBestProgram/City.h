#pragma once
#include <iostream>
#include <vector>

using namespace std;
class City
{
private:
	string name;
	int latitude, longitude;
	vector<City> vectorCity;
public:
	void addVector(City city);//���������� ������� � ������
	void setCity(string nameC, int latitudeC, int longitudeC);
};