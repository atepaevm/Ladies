#include "stdafx.h"
#include "Distance.h"
#include <vector>
#include "City.h"


void Distance::buildMatrix(vector <City> cityVec)
{
	for (vector<City>::iterator itA = cityVec.begin(); itA != cityVec.end(); itA++) {
		vector<double> row;
		for (vector<City>::iterator itB = cityVec.begin(); itB != cityVec.end(); itB++) {
			row.push_back(calculateDistance((*itA).latitude, (*itA).longitude, (*itB).latitude, (*itB).longitude));
		}
		distanceVec.push_back(row);
	}



}

void Distance::showMatrix()
{
	for (vector<vector<double >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++) {
		for (vector<double>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			cout << *it << "   "; 
		}
		cout <<endl<< "==================\n";
	}
}

double Distance::calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2)
{
	double distance;
	distance = sqrt(pow(latitude1 - latitude2,2) + pow(longitude1 - longitude2,2));
	return distance;
}
