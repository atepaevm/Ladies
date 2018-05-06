#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include "City.h"
#include "DistanceMatrix.h"
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;

string getNearest(double lat, double lon, std::vector<City>& cityVec)
{
	double distance;
	double nearest = 100000;
	string city;
	for each (City c in cityVec)
	{
		distance = sqrt(pow(lat - c.latitude, 2) + pow(lon - c.longitude, 2));
		if (distance < nearest) {
			nearest = distance;
			city = c.name;
		}
	}
	return city;
}

int main()
{
	vector <City> cityVec;
	int const bufSize = 255;
	int const countOfCities = 49;
	char buff[bufSize]; // ����� �������������� �������� ������������ �� ����� ������
	ifstream fin("..\\data\\data.csv"); // ������� ���� ��� ������
	fin.getline(buff, bufSize); //������ ������ ��� �� ����������
	int i = 0; //�������
	string name = "";
	double latitude = 0, longitude = 0;
	for (int j = 0; j<countOfCities && !fin.eof(); ++j)
	{
		fin.getline(buff, bufSize); // ������� ������ �� �����
		char * pch = strtok(buff, ","); // �������� �����������
		i = 0;
		while (pch != NULL)                         // ���� ���� �������
		{
			switch (i)
			{
			case 0:
				name = pch;
				break;
			case 2:
				latitude = atof(pch);
				break;
			case 3:
				longitude = atof(pch);
				break;
			default:
				break;
			}

			pch = strtok(NULL, ",");
			++i;
		}

		cityVec.push_back(City(name, latitude, longitude));
	}
	fin.close(); // ��������� ����

	DistanceMatrix distance(cityVec);
	distance.showMatrix();
	double lat = 55.33996;
	double lon = 86.08998;
	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "The nearest city to " << std::setprecision(5) << lat << ", " << lon << " is " << getNearest(lat, lon, cityVec) << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "mean = " << distance.getMean() << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "dispersion = " << distance.getDispersion() << endl;

	system("pause");
	return 0;

}

