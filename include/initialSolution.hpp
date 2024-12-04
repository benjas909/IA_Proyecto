#ifndef INITIALSOLUTION_HPP
#define INITIALSOLUTION_HPP
#include "./problemReader.hpp"
#include "./solutionWriter.hpp"
#include "./solution.hpp"

int randInt(int low, int high);

float randFloat();

Solution randomSol(TUP* problem, int d1, int d2);

Solution greedy(TUP* problem, int d1, int d2);

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat);

vector<vector<int>> transposeVector(const vector<vector<int>>& vec);

int partialCost(TUP* problem, int d1, int d2, vector<int> lastSeen, vector<int> lastVisit, vector<int> game, int currCity);

vector<int> findLowest(vector<vector<int>> assignCosts, vector<int> assignedUmps, vector<int> assignedGames);




#endif