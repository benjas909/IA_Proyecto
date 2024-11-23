#ifndef INITIALSOLUTION_HPP
#define INITIALSOLUTION_HPP
#include "./problemReader.hpp"
#include "./solution.hpp"

int randInt(int low, int high);

Solution randomSol(TUP* problem, int d1, int d2);

// Solution greedy(TUP* problem);

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat);

// int calcCost(TUP* problem, vector<int> game, vector<int> visits, vector<int> lastSeen);

vector<vector<int>> transposeVector(const vector<vector<int>>& vec);


#endif