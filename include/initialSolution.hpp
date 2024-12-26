#ifndef INITIALSOLUTION_HPP
#define INITIALSOLUTION_HPP
#include "./problemReader.hpp"
#include "./solutionWriter.hpp"
#include "./solution.hpp"

/**
 * @brief Generates a random int from a range, both bounds included
 *
 * @param low lower bound
 * @param high higher bound
 * @return int
 */
int randInt(int low, int high);

/**
 * @brief Generates a random floating point number between 0 and 1
 *
 * @return float
 */
float randFloat();

/**
 * @brief random algorithm to generate a random solution
 *
 * @param problem TUP object representing the problem
 * @param d1
 * @param d2
 * @return Solution
 */
Solution randomSol(TUP* problem, int d1, int d2);

/**
 * @brief Greedy algorithm to create an initial solution
 *
 * @param problem TUP object representing the problem
 * @param d1
 * @param d2
 * @return Solution
 */
Solution greedy(TUP* problem, int d1, int d2);

/**
 * @brief Checks the distance between the current place and a hypothetical next place
 *
 * @param currCity Current city
 * @param nextCity Next candidate city
 * @param distMat Distance matrix
 * @return int
 */
int nextDist(int currCity, int nextCity, vector<vector<int>> distMat);

/**
 * @brief Transposes a 2D Matrix
 *
 * @param vec 2D vector
 * @return vector<vector<int>>
 */
vector<vector<int>> transposeVector(const vector<vector<int>>& vec);

/**
 * @brief Computes the partial cost of choosing a certain umpire-game pairing
 *
 * @param problem TUP object representing the problem
 * @param d1
 * @param d2
 * @param lastSeen Vector containing counters for the number of rounds since each umpire saw each team
 * @param lastVisit Vector containing counters for the number of rounds since each umpire visited each team's home
 * @param game 3-tuple containing game information
 * @param currCity Current city
 * @return int
 */
int partialCost(TUP* problem, int d1, int d2, vector<int> lastSeen, vector<int> lastVisit, vector<int> game, int currCity);

/**
 * @brief Finds the index of the umpire-game pairing with the lowest cost
 *
 * @param assignCosts Assignation costs
 * @param assignedUmps Binary vector containing which umpires have already been assigned
 * @param assignedGames Binary vector containing which games have already been assigned an umpire
 * @return vector<int>
 */
vector<int> findLowest(vector<vector<int>> assignCosts, vector<int> assignedUmps, vector<int> assignedGames);




#endif