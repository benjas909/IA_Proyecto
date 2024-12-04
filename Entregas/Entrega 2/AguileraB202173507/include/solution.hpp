#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include "./TUP.hpp"
#include "./constraints.hpp"
// #include <vector>
// #include <iostream>
// #include <limits>



namespace constants {
  const int INF = 1000000000;
  const int PENALTY = 10000;
}

vector<int> updateLastVisitedMat(vector<int> lastVisited, int place);
vector<int> updateLastSeenMat(vector<int> lastSeen, int team1, int team2);
class Solution {
  TUP* problem;
  int distance;
  int d1;
  int d2;
  int totalCost;
  int teamViolations;
  int placeViolations;
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
  int getd1();
  int getd2();
  int getTeamViolations();
  int getPlaceViolations();
  TUP* getProblem();
  vector<vector<int>> getVisitsMatrix() const;
  vector<vector<vector<int>>> getGameAssignMat() const;

  void showVisitsMatrix();
  void showGameAssignMat();


  vector<vector<int>> swapVEdges(int r, int u1, int u2);

  vector<vector<vector<int>>> swapGEdges(int r, int u1, int u2);

};

#endif