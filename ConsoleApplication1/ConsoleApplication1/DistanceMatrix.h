#pragma once
#include <iostream>
#include <vector>
#include "City.h"

class DistanceMatrix
{
public:
	vector <vector<double>> distanceVec;
	void showMatrix();// ������� ������ �� �������
	double calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2);//������� ���������� ����� 1-�� � 2-�� ��������
	DistanceMatrix(vector<City>& cityVec);
	double getMean();
	double getDispersion();
};

