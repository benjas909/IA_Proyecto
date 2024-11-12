#include "../include/TUP.hpp"
#include "../include/problemReader.hpp"


using namespace std;

TUP readProblemFile(string fileName) {

  ifstream pFile(fileName);

  string line;

  vector<vector<int>> distMatrix;
  vector<vector<int>> oppMatrix;

  getline(pFile, line);;
  int N = stoi(line);

  for (int i = 0; i < 2 * N; i++) {
    getline(pFile, line);
    istringstream iss(line);
    vector<int> rowVec;

    for (int i; iss >> i; rowVec.push_back(i));

    distMatrix.push_back(rowVec);
  }

  for (int i = 0; i < 4 * N - 2; i++) {
    getline(pFile, line);
    istringstream iss(line);
    vector<int> rowVec;

    for (int i; iss >> i; rowVec.push_back(i));

    oppMatrix.push_back(rowVec);
  }

  TUP prob(N, distMatrix, oppMatrix);

  return prob;

}



