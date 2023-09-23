#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "csvstream.h"
#include "team.h"

using namespace std;

class Driver {
private:
	string input_file; 
	double t1_overall;
	double t2_overall; 


	// Key = team; Value = offensive points
	map<string, double> offensive_points;

	// Key = team; Value = defensive points 
	map<string, double> defensive_points;


	// Key = team; Value = rebounds
	map<string, double> num_rebounds;

	// Key = team; Value = games played
	map<string, int> gms_played; 


public:
	
	Driver(string finput) {
		finput = input_file; 
	}

	void read(string inFile) {
		// Creates csvstream object
		// And opens file


		csvstream csvin(inFile);

		// Key = column name  Value = cell datum
		map<string, string> row;


		while (csvin >> row) {
			add_offensive_points(row["Team"], row["PTS"]);
			add_defensive_points(row["Team"], row["OPTS"]);
			add_rebounds(row["Team"], row["OPTS"]);
			add_games_played(row["Team"], row["PTS"]);
		}


	}

	void add_offensive_points(string team, string points) {
		double num_points = stod(points);
		offensive_points[team] = num_points;
	}

	void add_defensive_points(string team, string points) {
		double num_defensive_points = stod(points);
		defensive_points[team] = num_defensive_points;
	}

	void add_rebounds(string team, string rebounds) {
		double number_rebounds = stod(rebounds);
		num_rebounds[team] = number_rebounds;
	}

	void add_games_played(string team, string gs_played) {
		int games_played = stoi(gs_played);

		gms_played[team] = games_played; 
	}

	void reg_or_playoffs(string team) {
		if (gms_played[team] >= 82) {
			cout << "playoff series!";
		}
		else {
			cout << "game!";
		}
	}

	// Computes team statistics 
	void run_team(Team team1_in, Team team2_in) {
		t1_overall += team1_in.opts_value(offensive_points);
		t1_overall += team1_in.dpts_value(defensive_points);
		t1_overall += team1_in.rbs_value(num_rebounds);

		t2_overall += team2_in.opts_value(offensive_points);
		t2_overall += team2_in.dpts_value(defensive_points);
		t2_overall += team2_in.rbs_value(num_rebounds);

		winner(team1_in, team2_in);
	}
	

	void winner(Team team_one, Team team_two) {
		if (t1_overall > t2_overall) {
			cout << "We predict that the " << team_one.get_name() << " will win the ";
			reg_or_playoffs(team_one.get_name());
		}
		else if (t1_overall == t2_overall) {
			int random_number = rand() % 10 + 1; 

			if (random_number < 5) {
				cout << "We predict that the " << team_one.get_name() << " will win the ";
				reg_or_playoffs(team_one.get_name());
			}
			else {
				cout << "We predict that the " << team_two.get_name() << " will win the ";
				reg_or_playoffs(team_two.get_name());
			}

		}
		else
		{
			 cout << "We predict that the " << team_two.get_name() << " will win the ";
			 reg_or_playoffs(team_two.get_name());
		}
	}


};


int main(int argc, char* argv[]) {
	
	// Error Checking
	if (argc != 2) {
		return 1; 
	}

	string inFile = argv[1];
	ifstream fin(inFile);


	if (!fin.is_open()) {
		cout << "Unable to open " << inFile << endl;
		return 1;
	}


	
	// Main Program 
	cout << "Welcome to win predictor!" << endl << endl;
	
	
	string team1;
	string team2;

	cout << "Simply enter the names of the two teams competing and we will make a prediction" << endl << endl; 

	getline(cin, team1);
	getline(cin, team2); 

	cout << endl; 

	// Initialize teams
	Team team_one(team1);
	Team team_two(team2);

	// Initialize driver program
	Driver first_team(inFile);
	first_team.read(inFile);
	first_team.run_team(team_one, team_two);





}