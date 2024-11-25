#include "../include/simAnnealing.hpp"

Solution randomSwap(Solution* sol) {
  int nRounds = sol->getProblem()->getnRounds();
  int nUmps = sol->getProblem()->getnUmpires();
  int nGames = nUmps;

  int r = randInt(0, nRounds - 1);
  int u1 = randInt(0, nUmps);
  int u2 = randInt(0, nUmps - 1);
  while (u1 == u2) {
    u2 = randInt(0, nUmps - 1);
  }

  vector<vector<int>> newVMat = sol->swapVEdges(r, u1, u2);
  vector<vector<vector<int>>> newGMat = sol->swapGEdges(r, u1, u2);

  Solution newSol(sol->getProblem(), sol->getd1(), sol->getd2(), newVMat, newGMat);

  return newSol;

}

Solution simulatedAnnealing(TUP* problem, Solution* initialSolution) {

}