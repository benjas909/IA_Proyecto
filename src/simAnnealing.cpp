#include "../include/simAnnealing.hpp"

Solution randomSwap(Solution* sol) {
  int nRounds = sol->getProblem()->getnRounds();
  int nUmps = sol->getProblem()->getnUmpires();

  int r = randInt(0, nRounds - 1);
  int u1 = randInt(0, nUmps - 1);
  int u2 = randInt(0, nUmps - 1);
  while (u1 == u2) {
    u2 = randInt(0, nUmps - 1);
  }

  vector<vector<int>> newVMat = sol->swapVEdges(r, u1, u2);
  vector<vector<vector<int>>> newGMat = sol->swapGEdges(r, u1, u2);

  Solution newSol(sol->getProblem(), sol->getd1(), sol->getd2(), newVMat, newGMat);

  return newSol;

}

Solution simulatedAnnealing(TUP* problem, Solution* initialSolution, int initialTemp, float p) {
  int temp = initialTemp;
  Solution currSol = *initialSolution;
  Solution bestSol = *initialSolution;
  Solution newSol = *initialSolution;
  int currCost = currSol.getTotalCost();
  int bestCost = bestSol.getTotalCost();
  int newCost;
  int minTemp = floor(initialTemp / 4);
  int maxIters = 2500;
  int it;
  int delta = 0;

  while (temp > minTemp) {
    cout << "Temp: " << temp << endl;
    it = 0;
    cout << endl << endl << "best cost right now: " << bestCost << endl << endl;

    while (it < maxIters) {
      newSol = randomSwap(&currSol);
      newCost = newSol.getTotalCost();
      delta = newCost - currCost;

      if ((newCost <= currCost) || (randFloat() < exp(-abs(delta) / temp))) {
        currSol = newSol;
        currCost = newSol.getTotalCost();
        cout << endl << "##############################" << endl;
        cout << "New Current Solution: " << endl;
        cout << "Distance: " << currSol.getDistance() << " | ";
        cout << "Total Cost: " << currSol.getTotalCost() << " | ";
        cout << "Team Violations: " << currSol.getTeamViolations() << " | ";
        cout << "Place Violations: " << currSol.getPlaceViolations() << endl;
        cout << "##############################" << endl << endl;

      }
      // cout << bestSol.getTotalCost() << endl;
      // cout << newCost << " vs " << bestCost << endl;
      if (newCost < bestCost) {
        // free(bestSol);
        cout << endl << "************************" << endl;
        // cout << bestSol->getTotalCost() << " -> " << currSol->getTotalCost() << endl;
        bestSol = newSol;
        currSol = newSol;
        currCost = bestCost = newSol.getTotalCost();
        cout << "New Best Solution: " << endl;
        cout << "Distance: " << bestSol.getDistance() << endl;
        cout << "Total Cost: " << bestSol.getTotalCost() << endl;
        cout << "Team Violations: " << bestSol.getTeamViolations() << endl;
        cout << "Place Violations: " << bestSol.getPlaceViolations() << endl;
        cout << "************************" << endl << endl;
      }
      it++;
    }
    temp *= p;
  }
  return bestSol;
}