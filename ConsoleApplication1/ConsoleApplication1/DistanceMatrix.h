#pragma once
#include <iostream>
#include <vector>
#include "City.h"

class DistanceMatrix
{
public:
	vector <vector<double>> distanceVec;
	void showMatrix();// выводит вектор на консоль
	double calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2);//считает расстояние между 1-ым и 2-ым городами
	DistanceMatrix(vector<City>& cityVec);
	double getMean();
	double getDispersion();
};

