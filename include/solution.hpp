#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include "./TUP.hpp"
#include "./constraints.hpp"
#include <vector>
#include <iostream>
#include <limits>



namespace constants {
  const int INF = 1000000;
  const int PENALTY = 1000;
}

class Solution {
  TUP* problem;
  int distance;
  int d1;
  int d2;
  int totalCost;
  vector<vector<int>> visitsMatrix;
  vector<vector<vector<int>>> gameAssignMat;

public:
  Solution(TUP* prob, int d1, int d2, vector<vector<int>> vMat, vector<vector<vector<int>>> gameAssignMat);
  int calcDistance();
  int calcTotalCost();
  int calcPlacePenalties();
  int calcTeamPenalties();

  int getDistance();
  int getTotalCost();
  vector<vector<int>> getVisitsMatrix();
  void showVisitsMatrix();
  void showGameAssignMat();

  vector<int> updateLastVisitedMat(vector<int> lastVisited, int ump, int place);
  vector<int> updateLastSeenMat(vector<int> lastSeen, int ump, int team1, int team2);

};

#endif