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

float randFloat() {
  return ((double)rand() / (double)RAND_MAX);
}

Solution randomSol(TUP* problem, int d1, int d2) {
  vector<vector<int>> assignments;
  vector<vector<vector<int>>> gameAssignment;
  vector<vector<vector<int>>> games = problem->getGamesMatrix();

  for (int r = 0; r < problem->getnRounds(); r++) {
    vector<int> roundV;
    vector<vector<int>> roundG;
    vector<int> occupied(problem->getnUmpires(), 0);

    for (int u = 0; u < problem->getnGamesPerRound(); u++) {
      int choice = randInt(0, problem->getnGamesPerRound() - 1);
      while (occupied[choice]) {
        choice = randInt(0, problem->getnGamesPerRound() - 1);
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
  int nRounds = problem->getnRounds();
  // cout << "Rondas: " << nRounds << endl;
  int nUmps = problem->getnUmpires();
  int nGames = nUmps;
  vector<vector<vector<int>>> probGameMat = problem->getGamesMatrix();
  vector<vector<int>> assignCosts(nUmps, vector<int>(nGames, constants::INF));
  vector<vector<int>> vMat(nUmps, vector<int>(nRounds, constants::INF));
  vector<vector<vector<int>>> gMat(nRounds, vector<vector<int>>(nUmps, vector<int>(3, constants::INF)));
  vector<vector<int>> lastVisit(nUmps, vector<int>(2 * nUmps, constants::INF));
  vector<vector<int>> lastSeen(nUmps, vector<int>(2 * nUmps, constants::INF));
  vector<vector<int>> assignedUmp(nRounds, vector<int>(nUmps, 0));
  vector<vector<int>> assignedGames(nRounds, vector<int>(nGames, 0));
  vector<int> currCities(nUmps, 0);
  vector<int> game(3, 0);
  vector<int> indToAssign = { -1, -1 };

  for (int r = 0; r < nRounds; r++) {
    for (int u = 0; u < nUmps; u++) {
      for (int g = 0; g < nGames; g++) {

        game = problem->getGamesMatrix()[r][g];
        assignCosts[u][g] = partialCost(problem, d1, d2, lastSeen[u], lastVisit[u], game, currCities[u]);

      }
    }
    for (int y = 0; y < nUmps; y++) {

      indToAssign = findLowest(assignCosts, assignedUmp[r], assignedGames[r]);

      if (assignedUmp[r][indToAssign[0]] == 0) {

        vMat[indToAssign[0]][r] = probGameMat[r][indToAssign[1]][2];
        gMat[r][indToAssign[0]] = probGameMat[r][indToAssign[1]];
        assignedUmp[r][indToAssign[0]] = 1;
        assignedGames[r][indToAssign[1]] = 1;
        currCities[indToAssign[0]] = probGameMat[r][indToAssign[1]][2];
        lastSeen[indToAssign[0]] = updateLastSeenMat(lastSeen[indToAssign[0]], probGameMat[r][indToAssign[1]][0], probGameMat[r][indToAssign[1]][1]);
        lastVisit[indToAssign[0]] = updateLastVisitedMat(lastVisit[indToAssign[0]], probGameMat[r][indToAssign[1]][2]);
      }

    }
  }

  Solution initialSol(problem, d1, d2, vMat, gMat);
  return initialSol;

}

int nextDist(int currCity, int nextCity, vector<vector<int>> distMat) {
  if (currCity == 0) {
    return 0;
  }
  return distMat[currCity - 1][nextCity - 1];
}


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

int partialCost(TUP* problem, int d1, int d2, vector<int> lastSeen, vector<int> lastVisit, vector<int> game, int currCity) {

  int teamViolations = checkTeamConstr(problem->getnUmpires(), d2, game, lastSeen);
  int placeViolations = checkPlaceConstr(problem->getnUmpires(), d1, game[2], lastVisit);
  int incentive = 0;
  int partialCost;

  if (lastVisit[game[2]] >= constants::INF) {
    incentive = 10000;
  }

  partialCost = nextDist(currCity, game[2], problem->getDistMatrix()) - incentive + constants::PENALTY * (teamViolations + placeViolations);

  return partialCost;

}

vector<int> findLowest(vector<vector<int>> assignCosts, vector<int> assignedUmps, vector<int> assignedGames) {
  int lowestCost = constants::INF;
  vector<int> lowestIndex(2, 999);


  for (size_t i = 0; i < assignCosts.size(); i++) {
    if (assignedUmps[i] == 1) {
      continue;
    }
    for (size_t j = 0; j < assignCosts[i].size(); j++) {
      if (assignedGames[j] == 1) {
        continue;
      }
      if (assignCosts[i][j] < lowestCost) {
        lowestCost = assignCosts[i][j];
        lowestIndex = { (int)i, (int)j };
      }
    }



  }
  return lowestIndex;
}