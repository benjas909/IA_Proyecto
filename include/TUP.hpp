#ifndef TUP_HPP
#define TUP_HPP

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class TUP {

  int nUmpires;
  int nTeams;
  int nRounds;
  int nGamesPerRound;
  vector<vector<int>> distMatrix;
  vector<vector<int>> oppMatrix;
  vector<vector<vector<int>>> gamesMatrix;

public:

  TUP(int N, vector<vector<int>> D, vector<vector<int>> T);

  int getnUmpires();
  int getnTeams();
  int getnRounds();
  int getnGamesPerRound();
  vector<vector<int>> getDistMatrix();
  vector<vector<int>> getOppMatrix();
  vector<vector<vector<int>>> getGamesMatrix();


  void showDistMatrix();
  void showOppMatrix();
  void showGamesMat();

  vector<vector<vector<int>>> generateGamesMat();

};

#endif