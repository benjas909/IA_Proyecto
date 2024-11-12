#include "../include/problemReader.hpp"
using namespace std;



int main() {

  TUP problem = readProblemFile("./instances/umps10.txt");
  cout << problem.getnRounds() << endl;

  problem.showDistMatrix();
  cout << endl;
  problem.showOppMatrix();

  return 0;
}