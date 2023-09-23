#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "team.h"


using namespace std;

Team::Team(string name_in) {
	name = name_in; 
}

string Team::get_name() {
	return name; 
}

double Team::opts_value(map<string, double>& offensive_points) {
		
	// finds minimum number of offensive points
	double min = (offensive_points.begin())->second; 
	for (auto it : offensive_points) {
		if (it.second < min) {
			min = it.second; 
		}
	}

	// Compute overall for team1 
	double difference = offensive_points[name] - min; 

	return 0.25 * difference; 


}

double Team::dpts_value(map<string, double>& defensive_points) {
	// Find maximum number of defensive points
	double max = (defensive_points.begin())->second; 

	for (auto it : defensive_points) {
		if (it.second > max) {
			max = it.second; 
		}
	}

	double difference = max - defensive_points[name];

	return 0.25 * difference; 
}

double Team::rbs_value(map<string, double>& num_rebounds) {
	
	// Find minimum number of rebounds 
	double min = (num_rebounds.begin())->second; 

	for (auto it : num_rebounds) {
		if (it.second < min) {
			min = it.second; 
		}
	}

	double difference = num_rebounds[name] - min; 

	return 0.125 * difference; 

}

double Team::compute_optscorrelation() {

}

	
