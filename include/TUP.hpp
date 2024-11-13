#ifndef TUP_HPP
#define TUP_HPP

#include <vector>
#include <iostream>

using namespace std;

class TUP {

  int nUmpires;
  int nTeams;
  int nRounds;
  vector<vector<int>> distMatrix;
  vector<vector<int>> oppMatrix;
  vector<vector<int>> gamesMatrix;
public:

  TUP(int N, vector<vector<int>> D, vector<vector<int>> T);

  int getnUmpires();
  int getnTeams();
  int getnRounds();
  vector<vector<int>> getDistMatrix();
  vector<vector<int>> getOppMatrix();
  vector<vector<int>> getGamesMatrix();

  void showDistMatrix();
  void showOppMatrix();
  void showGamesMat();

  vector<vector<int>> generateGamesMat();




};

#endif