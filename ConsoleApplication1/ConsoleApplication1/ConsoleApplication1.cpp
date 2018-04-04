#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<string.h>
#include "City.h"
#include "Distance.h"
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	vector <City> cityVec;
	//setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	char buff[100]; // буфер промежуточного хранения считываемого из файла текста
	ifstream fin("C:\\Users\\Евгения\\Downloads\\city_data.csv"); // открыли файл для чтения
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
			
			char* s = "34.32";
			double f = atof(s);

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

	system("pause");
	return 0;

}