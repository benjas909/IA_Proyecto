#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include <vector>
#include "./TUP.hpp"
#include <iostream>


class Solution {
  TUP* problem;
  int distance;
  int d1;
  int d2;
  vector<vector<int>> visitsMatrix;

public:
  Solution(TUP* prob, int d1, int d2, vector<vector<int>> vMat);
  int calcDistance();
  int getDistance();
  void showVisitsMatrix();
};

#endif