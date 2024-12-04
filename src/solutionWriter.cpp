#include "../include/solutionWriter.hpp"

void solutionWriter(Solution sol, string instName) {
  int nUmps = sol.getProblem()->getnUmpires();
  int d1 = sol.getd1();
  int d2 = sol.getd2();

  string fileName = instName + "_" + to_string(nUmps - d1) + "_" + to_string((int)floor(nUmps / 2) - d2) + ".txt";
  cout << fileName << endl;
  ofstream solFile("./solutions/" + fileName);

  solFile << to_string(sol.getDistance()) << "\n";
  solFile << to_string(d1) << " " << to_string(d2) << "\n";

  for (const auto& v : sol.getVisitsMatrix()) {
    for (const auto n : v) {
      solFile << n << " ";
    }
    solFile << "\n";
  }


  solFile.close();
}


// void Solution::showVisitsMatrix() {
//   for (const auto& v : this->visitsMatrix) {
//     for (const auto n : v) {
//       cout << n << " ";
//     }

//     cout << '\n';
//   }
// }