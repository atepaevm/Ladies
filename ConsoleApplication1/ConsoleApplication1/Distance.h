#pragma once
#include <iostream>
#include <vector>
#include "City.h"


class Distance
{
private:
	vector <vector<float>> distanceVec;
public:
	void buildMatrix(vector <City> cityVec);// строи вектор векторов расстояний до i-го города
	void showMatrix();// выводит вектор на консоль
	float calculateDistance(float latitude1, float longitude1, float latitude2, float longitude2);//считает расстояние между 1-ым и 2-ым городами
};

