#include "../include/problemReader.hpp"
#include "../include/solution.hpp"
#include "../include/initialSolution.hpp"


int main() {

  TUP problem = readProblemFile("./instances/umps4.txt");
  // cout << problem.getnRounds() << endl;

  // problem.showDistMatrix();
  // cout << endl;
  // problem.showOppMatrix();

  vector<vector<int>> visit = {
    {2, 1, 3, 4, 2, 4},
    {1, 3, 1, 3, 4, 2}
  };

  Solution sol(&problem, 0, 0, visit);

  // sol.showVisitsMatrix();

  cout << sol.getDistance() << endl;

  problem.showGamesMat();

  Solution ranSol = randomSol(&problem, 0, 0);

  ranSol.showVisitsMatrix();
  cout << ranSol.getDistance() << endl;



  return 0;
}