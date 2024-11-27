#ifndef INITIALSOLUTION_HPP
#define INITIALSOLUTION_HPP
#include "./problemReader.hpp"
#include "./solution.hpp"

int randInt(int low, int high);

float randFloat();

Solution randomSol(TUP* problem, int d1, int d2);

Solution greedy(TUP* problem, int d1, int d2);

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat);

// int calcCost(TUP* problem, vector<int> game, vector<int> visits, vector<int> lastSeen);

vector<vector<int>> transposeVector(const vector<vector<int>>& vec);

int partialCost(TUP* problem, int d1, int d2, vector<int> lastSeen, vector<int> lastVisit, int Ump, vector<int> game, int currCity);

vector<int> findLowest(vector<vector<int>> assignCosts, vector<int> assignedUmps, vector<int> assignedGames);


// vector<int> updateLastVisitedMat(vector<int> lastVisited, int place) {

//   for (int j = 0; j < (int)(lastVisited.size()); j++) {
//     if ((place - 1) == j) {
//       continue;
//     }
//     lastVisited[j]++;
//   }

//   return lastVisited;
// }

// vector<int> updateLastSeenMat(vector<int> lastSeen, int team1, int team2) {

//   for (int j = 0; j < (int)(lastSeen.size()); j++) {
//     if (((team1 - 1) == j) || ((team2 - 1) == j)) {
//       continue;
//     }
//     lastSeen[j]++;
//   }

//   return lastSeen;
// }


#endif