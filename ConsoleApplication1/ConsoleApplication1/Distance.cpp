#include "stdafx.h"
#include "Distance.h"
#include <vector>
#include "City.h"


Distance::Distance(vector <City>& cityVec)
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
			
	/*
	int i = 0; int j = 0;
	for (vector<City>::iterator itA = cityVec.begin(); itA != cityVec.end(); itA++) {
		for (vector<City>::iterator itB = cityVec.begin(); itB != cityVec.end(); itB++) {
			distanceVec[i][j] = calculateDistance((*itA).latitude, (*itA).longitude, (*itB).latitude, (*itB).longitude);
			++j;
		}
		++i;
		j = 0;
	}
	
	
	/*
	for (int i = 0; i < 5; i++)
	{
		vector<double> row;
		for (int j = 0; j < 5; j++)
		{
			row.push_back(0);
		}
		distanceVec.push_back(row);
	}
	*/

};
/*
void Distance::buildMatrix(vector <City>& cityVec)
{
	int i = 0;int j=0;

	for (vector<City>::iterator itA = cityVec.begin(); itA != cityVec.end(); itA++) {
		for (vector<City>::iterator itB = cityVec.begin(); itB != cityVec.end(); itB++) {
			distanceVec[i][j]=calculateDistance((*itA).latitude, (*itA).longitude, (*itB).latitude, (*itB).longitude);
			++j;
		}
		++i;
		j = 0;
	}



}
*/

//TODO: rewrite it in good way
void Distance::showMatrix()
{	
	for (auto vec : this->distanceVec) {
		for (auto val : vec)
			std::cout << val << " ";
		std::cout << std::endl;
	}
	
	/*
	for (vector<vector<double >>::iterator it2 = distanceVec.begin(); it2 != distanceVec.end(); it2++) {
		for (vector<double>::iterator it = (distanceVec.at(distance(distanceVec.begin(), it2))).begin(); it != (distanceVec.at(distance(distanceVec.begin(), it2)).end()); it++) {
			cout << *it << "   "; 
		}
		cout <<endl<< "==================\n";
	}
	*/
}


//TODO: rewrite it. Google ортодрома
double Distance::calculateDistance(double latitude1, double longitude1, double latitude2, double longitude2)
{
	double distance;
	distance = sqrt(pow(latitude1 - latitude2,2) + pow(longitude1 - longitude2,2));
	return distance;
}

double Distance::getMean()
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

double Distance::getDispersion()
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