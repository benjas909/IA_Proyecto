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
public:

  TUP(int N, vector<vector<int>> D, vector<vector<int>> T);

  int getnUmpires();
  int getnTeams();
  int getnRounds();
  vector<vector<int>> getDistMatrix();
  vector<vector<int>> getOppMatrix();

  void showDistMatrix();
  void showOppMatrix();

};

#endif