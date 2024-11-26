#include "../include/simAnnealing.hpp"


int main() {

  TUP problem = readProblemFile("./instances/umps4.txt");

  problem.showGamesMat();

  Solution ranSol = randomSol(&problem, 2, 1);

  cout << "Matrix original de visitas: " << endl;
  ranSol.showVisitsMatrix();

  cout << "Matrix original de asignación de juegos: " << endl;
  ranSol.showGameAssignMat();

  cout << ranSol.getDistance() << endl;

  cout << ranSol.getTotalCost() << endl;

  Solution test = randomSwap(&ranSol);

  // cout << "Matrix modificada de visitas: " << endl;
  // test.showVisitsMatrix();

  // cout << "Matrix modificada de asignación de juegos:" << endl;
  // test.showGameAssignMat();

  // cout << test.getDistance() << endl;
  // cout << test.getTotalCost() << endl;

  Solution bestSol = simulatedAnnealing(&problem, &ranSol, 2000, 0.95);

  cout << "SA result dist: " << bestSol.getDistance() << endl;
  cout << "SA result cost: " << bestSol.getTotalCost() << endl;

  cout << "Best solution: " << endl;
  cout << "Team Violations: " << bestSol.getTeamViolations() << endl;
  cout << "Place Violations: " << bestSol.getPlaceViolations() << endl;

  // for (int f = 0; f < 10; f++) {
  //   cout << randFloat(0.0, 1.0) << " ";
  // }
  // cout << endl;



  return 0;
}