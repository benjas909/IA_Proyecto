#include "../include/simAnnealing.hpp"


int main() {

  TUP problem = readProblemFile("./instances/umps4.txt");

  vector<vector<int>> visit = {
    {2, 1, 3, 4, 2, 4},
    {1, 3, 1, 3, 4, 2}
  };

  problem.showGamesMat();

  Solution ranSol = randomSol(&problem, 0, 0);

  cout << "Matrix original de visitas: " << endl;
  ranSol.showVisitsMatrix();

  cout << "Matrix original de asignación de juegos: " << endl;
  ranSol.showGameAssignMat();

  cout << ranSol.getDistance() << endl;

  cout << ranSol.getTotalCost() << endl;

  Solution test = randomSwap(&ranSol);

  cout << "Matrix modificada de visitas: " << endl;
  test.showVisitsMatrix();

  cout << "Matrix modificada de asignación de juegos:" << endl;
  test.showGameAssignMat();

  cout << test.getDistance() << endl;
  cout << test.getTotalCost() << endl;



  return 0;
}