#include "../include/initialSolution.hpp"
#include <random>
#include <limits>
#include <unistd.h>
#include <algorithm>

using namespace std;

namespace constants {
  const int INF = std::numeric_limits<int>::max();
}


// Genera entero random en un rango inclusivo en ambos límites
int randInt(int low, int high) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(low, high);

  return distr(gen);
}



Solution greedy(TUP* problem, int d1, int d2) {
  int nUmps = problem->getnUmpires();
  int nTeams = problem->getnTeams();
  int nRounds = problem->getnRounds();

  vector<vector<int>> lastVisit; // Vector de NxE, guarda la cantidad de slots desde que estuvo en cada sede
  vector<vector<int>> lastSeenTeam; // Vector de NxE, guarda la cantidad de slots desde que arbitró a cada equipo
  vector<vector<int>> assignUmp;



  // for (int i = 0; i < problem->getnRounds(); i++) {
  //   vector<int> currUmp;
  //   assignUmp.push_back(currUmp);
  //   if (i == 0) {
  //     int choice = randInt(1, nUmps);
  //     currRound.push_back(choice);
  //   }
  //   else {
  //     int best = constants::INF;
  //     for (int j = 0; j < nUmps; j++) {

  //     }
  //   }
  // }

}

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat) {
  return distMat[currCity - 1][nextCity - 1];
}

bool findGame(vector<vector<string>> games, vector<string> match) {
  bool found = (find(games.begin(), games.end(), match) != games.end());
  return found;
}