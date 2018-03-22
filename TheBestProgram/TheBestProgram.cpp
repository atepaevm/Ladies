// TheBestProgram.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "City.h"


using namespace std;


int main()
{
	City city;
	city.setCity("Moscow",456,332);
	city.addVector(city);
    return 0;
}

