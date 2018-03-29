#pragma once
#include <iostream>
#include <vector>
#include "City.h"


class Distance
{
private:
	vector <vector<float>> distanceVec;
public:
	void buildMatrix(vector <City> cityVec);// ����� ������ �������� ���������� �� i-�� ������
	void showMatrix();// ������� ������ �� �������
	float calculateDistance(float latitude1, float longitude1, float latitude2, float longitude2);//������� ���������� ����� 1-�� � 2-�� ��������
};

