#include "stdafx.h"
#include "DistanceMatrix.h"
#include <vector>
#include "City.h"
//#include <cmath>

DistanceMatrix::DistanceMatrix(vector <City>& cityVec)
{
	//matrix init
	unsigned size = cityVec.size();
	for (int i = 0; i < size; ++i)
		this->distanceVec.push_back(std::vector<double>(size));
	//matrix counting
	for (int i = 0; i < cityVec.size(); ++i) {
		City first = cityVec[i];
		for (int j = 0; j < cityVec.size(); ++j) {			
			City second = cityVec[j];
			this->distanceVec[i][j] = this->calculateDistance(first.latitude,
				first.longitude, second.latitude, second.longitude);
		}
	}
};

//TODO: rewrite it in good way
void DistanceMatrix::showMatrix()
{	
	for (auto vec : this->distanceVec) {
		for (auto val : vec)
			std::cout << val << " ";
		std::cout << std::endl;
	}

}


//TODO: rewrite it. Google ортодрома
double DistanceMatrix::calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2)
{
	double distance;
	if ((latitude1== latitude2) && longitude1== longitude2)
		return distance=0;
	//distance =sqrt(pow(latitude1 - latitude2,2) + pow(longitude1 - longitude2,2));
	distance =111.3*acos(sin(latitude1) * sin(latitude2) + cos(latitude1) * cos(latitude2) * cos(longitude2 - longitude1));
	return distance;
}

double DistanceMatrix::getMean()
{
	double mean = 0;
	double sum = 0;
	int count = 0;
	//rewrite it!
	for (vector<vector<double >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++) 
		for (vector<double>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			if (*it != 0) {
				++count;
				sum += *it;
			}
		}
	mean = sum / count;
	return mean;
}

double DistanceMatrix::getDispersion()
{
	double mean = getMean();
	double dispersion = 0;
	double sum = 0;
	int count = 0;
	//rewrite it!
	for (vector<vector<double >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++)
		for (vector<double>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			if (*it != 0) {
				++count;
				sum += (*it - mean)*(*it - mean);
			}
		}
	dispersion = sum / count;
	return sqrt(dispersion);
}
