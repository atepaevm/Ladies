#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include "City.h"
#include "Distance.h"
#include <stdlib.h>
#include <string>
using namespace std;

vector <City> cityVec;

string getNearest(double lat, double lon)
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
	
	//setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	char buff[100]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("C:\\Download\\data.csv"); // открыли файл для чтения
	fin.getline(buff, 100); //первая строка нас не интересует
	int i = 0; //счечик
	string name = "";
	double latitude = 0, longitude = 0;
	int j = 0;
//	while (!fin.eof())
	while (j < 5)
	{
		++j;
		City cit;
		fin.getline(buff, 100); // считали строку из файла
		char * pch = strtok(buff, ","); // замутили разделители
		i = 0;
		while (pch != NULL)                         // пока есть лексемы
		{
			if (i == 0) name = pch;
			if (i == 2) latitude = atof(pch);
			if (i == 3) longitude = atof(pch);
			if (i > 3) break;
			pch = strtok(NULL, ",");
			++i;
		}

		cit.setCity(name, latitude, longitude);
		cityVec.push_back(cit);
	}
	fin.close(); // закрываем файл

	Distance distance;
	distance.buildMatrix(cityVec);
	distance.showMatrix();
	
	double lat = 36.9316;
	double lon = 65.101;
	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "The nearest city to " << lat << ", " << lon << " is " << getNearest(lat, lon)<< endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "mean = " << distance.getMean() << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "dispersion = " << distance.getDispersion() << endl;

	system("pause");
	return 0;

}

