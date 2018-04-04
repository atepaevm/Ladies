#pragma once
#include <iostream>
#include <vector>
#include "City.h"


class Distance
{
public:
	vector <vector<double>> distanceVec;
	void buildMatrix(vector <City> cityVec);// ����� ������ �������� ���������� �� i-�� ������
	void showMatrix();// ������� ������ �� �������
	double calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2);//������� ���������� ����� 1-�� � 2-�� ��������
	Distance();
};

