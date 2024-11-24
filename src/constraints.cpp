#include "../include/constraints.hpp"

bool checkPlaceConstr(int nUmps, int d1, int place, vector<int> lastVisited) {
  int limit = nUmps - d1;

  if (lastVisited[place - 1] < limit) {
    return true;
  }
  return false;
}

int checkTeamConstr(int nUmps, int d2, vector<int> game, vector<int> lastSeen) {
  int limit = nUmps - floor(d2 / 2);
  int vioCounter = 0;
  if (lastSeen[game[0] - 1] < limit) {
    vioCounter++;
  }
  if (lastSeen[game[1] - 1] < limit) {
    vioCounter++;
  }

  return vioCounter;
}
