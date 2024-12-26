#ifndef TUP_HPP
#define TUP_HPP

#include <vector>
#include <stack>
#include <iostream>
#include <chrono>

using namespace std;

class TUP {

  int nUmpires;
  int nTeams;
  int nRounds;
  int nGamesPerRound;
  vector<vector<int>> distMatrix;
  vector<vector<int>> oppMatrix;

  // Auxiliar
  vector<vector<vector<int>>> gamesMatrix;

public:

  /**
   * @brief Construct a new TUP object
   *
   * @param N Number of umpires
   * @param D Distance matrix
   * @param T Tournament matrix
   */
  TUP(int N, vector<vector<int>> D, vector<vector<int>> T);

  /**
   * @brief Gets number of umpires
   *
   * @return int
   */
  int getnUmpires();

  /**
   * @brief Gets number of teams in the tournament
   *
   * @return int
   */
  int getnTeams();

  /**
   * @brief Gets number of rounds
   *
   * @return int
   */
  int getnRounds();

  /**
   * @brief Gets number of games per round
   *
   * @return int
   */
  int getnGamesPerRound();

  /**
   * @brief Get the Dist Matrix object
   *
   * @return vector<vector<int>>
   */
  vector<vector<int>> getDistMatrix();

  /**
   * @brief Get the Opp Matrix object
   *
   * @return vector<vector<int>>
   */
  vector<vector<int>> getOppMatrix();

  /**
   * @brief Get the Games Matrix object
   *
   * @return vector<vector<vector<int>>>
   */
  vector<vector<vector<int>>> getGamesMatrix();


  /**
   * @brief Prints distance matrix on screen
   *
   */
  void showDistMatrix();

  /**
   * @brief Prints tournament matrix on screen
   *
   */
  void showOppMatrix();

  /**
   * @brief Prints games matrix on screen
   *
   */
  void showGamesMat();

  /**
   * @brief Generates the games matrix
   *
   * @return vector<vector<vector<int>>>
   */
  vector<vector<vector<int>>> generateGamesMat();

};

#endif