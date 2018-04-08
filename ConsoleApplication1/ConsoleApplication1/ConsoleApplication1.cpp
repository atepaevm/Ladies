#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include "City.h"
#include "Distance.h"
#include <stdlib.h>
#include <string>
#include <iomanip>
using namespace std;



string getNearest(double lat, double lon,std::vector<City>& cityVec)
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
	int const countOfCities = 1000;
	char buff[bufSize]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("..\\data\\data.csv"); // открыли файл для чтения
	fin.getline(buff, bufSize); //первая строка нас не интересует
	int i = 0; //счетчик
	string name = "";
	double latitude = 0, longitude = 0;
	//int countOfCities = 0;
//	while (!fin.eof())
//while (countOfCities < 5)
	for(int j=0;j<countOfCities && !fin.eof();++j){
		//++countOfCities;
		//City cit;
		fin.getline(buff, bufSize); // считали строку из файла
		char * pch = strtok(buff, ","); // замутили разделители
		i = 0;
		while (pch != NULL)                         // пока есть лексемы
		{
			/*
			switch(i)
				case 0:
					name = pch;
					break;
				default:
			*/
			if (i == 0) name = pch;
			if (i == 2) latitude = atof(pch);
			if (i == 3) longitude = atof(pch);
			if (i > 3) break;
			pch = strtok(NULL, ",");
			++i;
		}

		//cit.setCity(name, latitude, longitude);
		cityVec.push_back(City(name,latitude,longitude));
	}
	fin.close(); // закрываем файл

	Distance distance(cityVec);
	//distance.buildMatrix(cityVec);
	//distance.showMatrix();
	
	double lat = 55.33996;
	double lon = 86.08998;
	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "The nearest city to " << std::setprecision(5)<<lat << ", " << lon << " is " << getNearest(lat, lon,cityVec)<< endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "mean = " << distance.getMean() << endl;

	cout << "---------------------------------------------------------------------------" << endl << endl;
	cout << "dispersion = " << distance.getDispersion() << endl;

	system("pause");
	return 0;

}

