#include "../include/solution.hpp"

Solution::Solution(TUP* prob, int d1, int d2, vector<vector<int>> vMat, vector<vector<vector<int>>> gameAssignMat) {
  this->problem = prob;
  this->d1 = d1;
  this->d2 = d2;
  this->visitsMatrix = vMat;
  // this->showVisitsMatrix();
  this->gameAssignMat = gameAssignMat;
  // this->showGameAssignMat();
  this->distance = Solution::calcDistance();
  this->totalCost = calcTotalCost();
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

int Solution::getTotalCost() {
  return this->totalCost;
}

vector<vector<int>> Solution::getVisitsMatrix() {
  return this->visitsMatrix;
}

void Solution::showVisitsMatrix() {
  // cout << "visitsMat rows: " << this->visitsMatrix.size() << endl;
  // cout << "visitsMat columns: " << this->visitsMatrix[0].size() << endl;
  for (const auto& v : this->visitsMatrix) {
    // cout << u++ << endl;
    for (const auto n : v) {
      cout << n << " ";
      // cout << o++ << endl;
    }

    cout << '\n';
  }
}

void Solution::showGameAssignMat() {
  cout << "Game Assign Matrix: " << endl;
  cout << "[ " << endl;
  for (const auto& v : this->gameAssignMat) {
    for (const auto& e : v) {
      cout << "{ ";
      for (const auto n : e) {
        cout << n << " ";
      }
      cout << "}";
    }
    cout << '\n';

  }
  cout << " ]" << endl;
}


int Solution::calcTotalCost() {
  int cost = this->getDistance() + constants::PENALTY * (this->calcPlacePenalties() + this->calcTeamPenalties());

  return cost;
}

int Solution::calcPlacePenalties() {
  int violations = 0;
  int nUmps = this->problem->getnUmpires();
  int nRounds = this->problem->getnRounds();
  vector<vector<int>> lastVisited(this->problem->getnUmpires(), vector<int>(this->problem->getnTeams(), constants::INF));

  for (int r = 0; r < this->problem->getnRounds(); r++) {
    for (int u = 0; u < nUmps; u++) {
      // Se puede hacer sin el if, sólo sumar al contador, luego lo veo
      // cout << "lastv[u] size: " << lastVisited[u].size() << endl;
      // cout << "place visited: " << this->visitsMatrix[u][r] << endl;

      if (checkPlaceConstr(nUmps, this->d1, this->visitsMatrix[u][r], lastVisited[u])) {
        violations++;
      }
      lastVisited[u] = this->updateLastVisitedMat(lastVisited[u], u, this->visitsMatrix[u][r]);
      lastVisited[u][this->visitsMatrix[u][r] - 1] = 0;

      // cout << "lastVisited for ump " << u + 1 << " " << endl;
      // for (int x = 0; x < (int)lastVisited[u].size(); x++) {
      //   cout << lastVisited[u][x] << " ";
      // }
      // cout << endl;
      // cout << endl;
    }
  }
  cout << "place violations: " << violations << endl;
  return violations;
}

int Solution::calcTeamPenalties() {
  int violations = 0;
  int nUmps = this->problem->getnUmpires();
  vector<vector<int>> lastSeen(this->problem->getnUmpires(), vector<int>(this->problem->getnTeams(), constants::INF));

  for (int r = 0; r < this->problem->getnRounds(); r++) {
    for (int u = 0; u < nUmps; u++) {

      // cout << "curr umpire: " << u + 1 << " in round: " << r + 1 << endl;
      // for (int e = 0; e < (int)gameAssignMat[r][u].size(); e++) {
      //   cout << gameAssignMat[r][u][e] << " ";
      // }
      // cout << endl;
      violations += checkTeamConstr(nUmps, this->d2, this->gameAssignMat[r][u], lastSeen[u]);

      lastSeen[u] = this->updateLastSeenMat(lastSeen[u], u, this->gameAssignMat[r][u][0], this->gameAssignMat[r][u][1]);
      lastSeen[u][this->gameAssignMat[r][u][0]] = 0;
      lastSeen[u][this->gameAssignMat[r][u][1]] = 0;
    }
  }
  cout << "team violations: " << violations << endl;
  return violations;
}


vector<int> Solution::updateLastVisitedMat(vector<int> lastVisited, int ump, int place) {

  for (int j = 0; j < (int)(lastVisited.size()); j++) {
    if ((place - 1) == j) {
      continue;
    }
    lastVisited[j]++;
  }

  return lastVisited;
}

vector<int> Solution::updateLastSeenMat(vector<int> lastSeen, int ump, int team1, int team2) {

  for (int j = 0; j < (int)(lastSeen.size()); j++) {
    if (((team1 - 1) == j) || ((team2 - 1) == j)) {
      continue;
    }
    lastSeen[j]++;
  }

  return lastSeen;
}