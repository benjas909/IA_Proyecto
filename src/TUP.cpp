#include "../include/TUP.hpp"

TUP::TUP(int N, vector<vector<int>> D, vector<vector<int>> T) {
  this->nUmpires = N;
  this->nTeams = 2 * nUmpires;
  this->nRounds = 4 * nUmpires - 2;
  this->nGamesPerRound = this->nUmpires;
  this->distMatrix = D;
  this->oppMatrix = T;
  this->gamesMatrix = TUP::generateGamesMat();
}

int TUP::getnUmpires() {
  return this->nUmpires;
}

int TUP::getnTeams() { return this->nTeams; }
int TUP::getnRounds() { return this->nRounds; }
int TUP::getnGamesPerRound() { return this->nGamesPerRound; }
vector<vector<int>> TUP::getDistMatrix() { return this->distMatrix; }
vector<vector<int>> TUP::getOppMatrix() { return this->oppMatrix; }
vector<vector<vector<int>>> TUP::getGamesMatrix() { return this->gamesMatrix; }

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

vector<vector<vector<int>>> TUP::generateGamesMat() {
  vector<vector<vector<int>>> gamesMat;
  for (int r = 0; r < this->getnRounds(); r++) {
    vector<vector<int>> round;
    for (int g = 0; g < this->getnTeams(); g++) {
      if (this->getOppMatrix()[r][g] < 0) {
        vector<int> game = { g + 1, abs(getOppMatrix()[r][g]) , abs(getOppMatrix()[r][g]) };
        round.push_back(game);
      }
    }
    gamesMat.push_back(round);
  }

  return gamesMat;
}

void TUP::showGamesMat() {
  cout << "[ " << endl;
  for (const auto& v : this->gamesMatrix) {
    for (const auto& e : v) {
      cout << "{ ";
      for (const auto n : e) {
        cout << n << " ";
      }
      cout << "}";
    }
    cout << '\n';

  }
  cout << " ]" << endl;
}