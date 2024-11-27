#ifndef CONSTRAINTS_HPP
#define CONSTRAINTS_HPP
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

// balls brother
int checkTeamConstr(int nUmps, int d2, vector<int> game, vector<int> lastSeen);

bool checkPlaceConstr(int nUmps, int d1, int place, vector<int> lastVisited);


#endif