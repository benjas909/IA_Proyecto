#include "../include/simAnnealing.hpp"

using namespace std::chrono;

int main(int argc, char* argv[]) {

  if (argc == 4) {
    string filename = (string)argv[1];

    cout << "filename: " << filename << endl;
    TUP problem = readProblemFile("./instances/" + filename + ".txt");

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

    int d1 = stoi(argv[2]);
    int d2 = stoi(argv[3]);
    cout << d1 << " " << d2 << endl;
    Solution greedySol = greedy(&problem, d1, d2);


    cout << "greedySol dist: " << greedySol.getDistance() << endl;
    cout << "greedySol total cost: " << greedySol.getTotalCost() << endl;
    cout << "Team Violations: " << greedySol.getTeamViolations() << endl;
    cout << "Place Violations: " << greedySol.getPlaceViolations() << endl;

    auto start = high_resolution_clock::now();
    Solution bestSol = simulatedAnnealing(&greedySol, 2000, 0.95);
    auto stop = high_resolution_clock::now();

    auto elapsed = duration_cast<seconds>(stop - start);

    cout << "SA result dist: " << bestSol.getDistance() << endl;
    cout << "SA result cost: " << bestSol.getTotalCost() << endl;
    cout << "Execution time: " << elapsed.count() << " s" << endl;

    cout << "Best solution: " << endl;
    cout << "Team Violations: " << bestSol.getTeamViolations() << endl;
    cout << "Place Violations: " << bestSol.getPlaceViolations() << endl;

    // bestSol.showVisitsMatrix();
    // cout << endl;
    // bestSol.showGameAssignMat();

    // for (int f = 0; f < 10; f++) {
    //   cout << randFloat(0.0, 1.0) << " ";
    // }
    // cout << endl;

    solutionWriter(bestSol, filename);
  }
  else {
    cerr << "Muy pocos argumentos." << endl;
    exit(1);
  }




  return 0;
}