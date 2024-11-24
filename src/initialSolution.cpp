#include "../include/initialSolution.hpp"
#include <random>
#include <limits>
#include <unistd.h>
#include <algorithm>


// namespace constants {
//   const int INF = std::numeric_limits<int>::max();
// }


// Genera entero random en un rango inclusivo en ambos límites
int randInt(int low, int high) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distr(low, high);

  return (int)distr(gen);
}

Solution randomSol(TUP* problem, int d1, int d2) {
  vector<vector<int>> assignments;
  vector<vector<vector<int>>> gameAssignment;
  vector<vector<vector<int>>> games = problem->getGamesMatrix();

  for (int r = 0; r < problem->getnRounds(); r++) {
    vector<int> roundV;
    vector<vector<int>> roundG;

    int occupied[problem->getnUmpires()];
    for (int u = 0; u < problem->getnGamesPerRound(); u++) {
      occupied[u] = 0;
    }

    for (int u = 0; u < problem->getnGamesPerRound(); u++) {
      int choice = randInt(0, problem->getnGamesPerRound());
      while (occupied[choice]) {
        choice = randInt(0, problem->getnGamesPerRound());
      }
      occupied[choice] = 1;
      roundV.push_back(games[r][choice][2]);
      roundG.push_back(games[r][choice]);
    }
    assignments.push_back(roundV);
    gameAssignment.push_back(roundG);
  }

  vector<vector<int>> transVMat = transposeVector(assignments);

  Solution initialSolution(problem, d1, d2, transVMat, gameAssignment);

  return initialSolution;

}

Solution greedy(TUP* problem, int d1, int d2) {
  int nUmps = problem->getnUmpires();
  int nTeams = problem->getnTeams();
  int nRounds = problem->getnRounds();
  int nGamesPerRound = problem->getnGamesPerRound();
  vector<vector<vector<int>>> gMatrix = problem->getGamesMatrix();

  vector<vector<int>> lastVisit; // Vector de NxE, guarda la cantidad de slots desde que estuvo en cada sede
  vector<vector<int>> lastSeenTeam; // Vector de NxE, guarda la cantidad de slots desde que arbitró a cada equipo
  vector<vector<int>> hasVisited;
  vector<vector<int>> umpAssignments;


  for (int r = 0; r < nRounds; r++) {
    for (int u = 0; u < nUmps; u++) {
      int occupied[nUmps];

      if (u == 0) {
        for (int a = 0; a < nUmps; a++) {
          occupied[a] = 0;
        }
      }

      for (int g = 0; g < nGamesPerRound; g++) {
        if (occupied[g] == 1) {
          continue;
        }
        else {

        }
      }

      // }
      //   int occupied[nUmps]; // Indica qué partidos están asignados
      //   if (r == 0) {
      //     for (int u = 0; u < nUmps; u++) {
      //       occupied[u] = 0;
      //     }
      //     for (int u = 0; u < nUmps; u++) {
      //       vector<int> umpChoice;
      //       int choice = randInt(1, nUmps);
      //       while (occupied[choice - 1] == 1) {
      //         choice = randInt(1, nUmps);
      //       }
      //       occupied[choice - 1] = 1;
      //       umpChoice.push_back(choice);
      //       assignUmp.push_back(umpChoice);
      //     }
      //   }
      //   else {

      //   }

      // }

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
    }

  }
}

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat) {
  return distMat[currCity - 1][nextCity - 1];
}

// bool findGame(vector<vector<string>> games, vector<int> match) {
//   bool found = (find(games.begin(), games.end(), match) != games.end());
//   return found;
// }

// int calcCost(TUP* problem, vector<int> game, vector<int> visits, vector<int> lastSeen) {

// }

vector<vector<int>> transposeVector(const vector<vector<int>>& vec) {
  if (vec.size() == 0) {
    return vec;
  }

  vector<vector<int>> transVec(vec[0].size(), vector<int>());

  for (int i = 0; i < (int)vec.size(); i++) {
    for (int j = 0; j < (int)vec[i].size(); j++) {
      transVec[j].push_back(vec[i][j]);
    }
  }
  return transVec;
}