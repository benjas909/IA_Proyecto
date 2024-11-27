#include "../include/simAnnealing.hpp"


int main() {

  TUP problem = readProblemFile("./instances/umps12.txt");

  problem.showGamesMat();

  // Solution ranSol = randomSol(&problem, 0, 0);

  // cout << "Matrix original de visitas: " << endl;
  // ranSol.showVisitsMatrix();

  // cout << "Matrix original de asignación de juegos: " << endl;
  // ranSol.showGameAssignMat();

  // cout << ranSol.getDistance() << endl;

  // cout << ranSol.getTotalCost() << endl;

  // Solution test = randomSwap(&ranSol);

  // cout << "Matrix modificada de visitas: " << endl;
  // test.showVisitsMatrix();

  // cout << "Matrix modificada de asignación de juegos:" << endl;
  // test.showGameAssignMat();

  // cout << test.getDistance() << endl;
  // cout << test.getTotalCost() << endl;

  Solution greedySol = greedy(&problem, -1, 1);

  cout << "greedySol dist: " << greedySol.getDistance() << endl;
  cout << "greedySol total cost: " << greedySol.getTotalCost() << endl;
  cout << "Team Violations: " << greedySol.getTeamViolations() << endl;
  cout << "Place Violations: " << greedySol.getPlaceViolations() << endl;

  Solution bestSol = simulatedAnnealing(&problem, &greedySol, 2000, 0.95);

  cout << "SA result dist: " << bestSol.getDistance() << endl;
  cout << "SA result cost: " << bestSol.getTotalCost() << endl;

  cout << "Best solution: " << endl;
  cout << "Team Violations: " << bestSol.getTeamViolations() << endl;
  cout << "Place Violations: " << bestSol.getPlaceViolations() << endl;

  bestSol.showVisitsMatrix();
  cout << endl;
  bestSol.showGameAssignMat();

  // for (int f = 0; f < 10; f++) {
  //   cout << randFloat(0.0, 1.0) << " ";
  // }
  // cout << endl;



  return 0;
}