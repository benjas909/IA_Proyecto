#include "../include/constraints.hpp"

bool checkPlaceConstr(int nUmps, int d1, int place, vector<int> lastVisited) {
  int limit = nUmps - d1;
  // cout << "place cons: " << limit << endl;

  if (lastVisited[place - 1] < limit - 1) {
    return true;
  }
  return false;
}

int checkTeamConstr(int nUmps, int d2, vector<int> game, vector<int> lastSeen) {
  int limit = (int)floor(nUmps / 2) - d2;
  // cout << "team cons: " << limit << endl;
  int vioCounter = 0;

  if (lastSeen[game[0] - 1] < limit - 1) {
    vioCounter++;
  }
  if (lastSeen[game[1] - 1] < limit - 1) {
    vioCounter++;
  }

  return vioCounter;
}
