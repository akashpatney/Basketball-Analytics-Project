#include <iostream>
#include <string>
#include <map>
#include <fstream>



using namespace std;

class Team {
private:
	string name; 
	double overall;
	

public:

	Team(string name_in);

	string get_name();

	double opts_value(map<string, double>& offensive_points);

	double dpts_value(map<string, double>& defensive_points);

	double rbs_value(map<string, double>& num_rebounds);

	double compute_optscorrelation();
};