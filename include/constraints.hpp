#ifndef CONSTRAINTS_HPP
#define CONSTRAINTS_HPP
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * @brief Checks the teams constraint and returns the number of infringements
 *
 * @param nUmps Number of umpires
 * @param d2 Problem parameter
 * @param game Vector containing game information
 * @param lastSeen Vector containing counters for the number of rounds since each umpire visited each team's home
 * @return int
 */
int checkTeamConstr(int nUmps, int d2, vector<int> game, vector<int> lastSeen);

/**
 * @brief Checks if a place assignment violates the place constraint
 *
 * @param nUmps Number of umpires
 * @param d1 Problem parameter
 * @param place Team's home to visit
 * @param lastVisited Vector containing counters for the number of rounds since each umpire visited each team's home
 * @return true
 * @return false
 */
bool checkPlaceConstr(int nUmps, int d1, int place, vector<int> lastVisited);


#endif