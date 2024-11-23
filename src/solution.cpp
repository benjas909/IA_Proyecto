#include "../include/solution.hpp"

Solution::Solution(TUP* prob, int d1, int d2, vector<vector<int>> vMat) {
  this->problem = prob;
  this->d1 = d1;
  this->d2 = d2;
  this->visitsMatrix = vMat;
  this->distance = Solution::calcDistance();
}

int Solution::calcDistance() {
  vector<vector<int>> distM = this->problem->getDistMatrix();
  int dist = 0;

  for (int j = 0; j < this->problem->getnUmpires(); j++) {
    for (int i = 1; i < this->problem->getnRounds(); i++) {
      dist += distM[this->visitsMatrix[j][i - 1] - 1][this->visitsMatrix[j][i] - 1];
    }
  }
  return dist;
}

int Solution::getDistance() {
  return this->distance;
}

void Solution::showVisitsMatrix() {
  for (const auto& v : this->visitsMatrix) {
    for (const auto n : v)
      cout << n << " ";
    cout << '\n';
  }
}
