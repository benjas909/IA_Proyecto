#include "../include/TUP.hpp"

using namespace std;



TUP::TUP(int N, vector<vector<int>> D, vector<vector<int>> T) {
  nUmpires = N;
  nTeams = 2 * nUmpires;
  nRounds = 4 * nUmpires - 2;
  distMatrix = D;
  oppMatrix = T;
}

int TUP::getnUmpires() {
  return this->nUmpires;
}

int TUP::getnTeams() { return this->nTeams; }
int TUP::getnRounds() { return this->nRounds; }

vector<vector<int>> TUP::getDistMatrix() { return this->distMatrix; }

vector<vector<int>> TUP::getOppMatrix() { return this->oppMatrix; }

void TUP::showDistMatrix() {
  for (const auto& v : this->distMatrix) {
    for (const auto n : v)
      cout << n << "  ";
    cout << '\n';
  }
}

void TUP::showOppMatrix() {
  for (const auto& v : this->oppMatrix) {
    for (const auto n : v)
      cout << n << " ";
    cout << '\n';
  }
}