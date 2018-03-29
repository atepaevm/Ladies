#include "stdafx.h"
#include "Distance.h"
#include "Distance.h"
#include <vector>
#include "City.h"
#define sqr(x) x*x


void Distance::buildMatrix(vector <City> cityVec)
{
	vector<City>::iterator itA = cityVec.begin();
	vector<City>::iterator itB = cityVec.begin();
	for (vector<vector<float >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++) {
		for (vector<float>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			*it = calculateDistance((*itA).latitude, (*itA).longitude, (*itB).latitude, (*itB).longitude);
			itB++;
		}
		itA++;
	}



}

void Distance::showMatrix()
{
	for (vector<vector<float >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++) {
		for (vector<float>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			cout << *it << "   "; 
		}
		cout << "==================\n";
	}
}

float Distance::calculateDistance(float latitude1, float longitude1, float latitude2, float longitude2)
{
	float distance;
	distance = sqrt(sqr(latitude1 - latitude2) + sqr(longitude1 - longitude2));
	return distance;
}
