#ifndef SOLUTION_HPP
#define SOLUTION_HPP
#include <vector>

using namespace std;


class Solution {
  int distance;
  int d1;
  int d2;
  vector<vector<int>> visitsMatrix;

  Solution(int dist, int d1, int d2, vector<vector<int>> vMat);
};

#endif