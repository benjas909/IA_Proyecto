#include "../include/constraints.hpp"

bool checkPlaceConstr(int nUmps, int d1, int place, vector<int> lastVisited) {
  int limit = nUmps - d1;

  if (lastVisited[place - 1] < limit) {
    return true;
  }
  return false;
}

int checkTeamConstr(int nUmps, int d2, vector<int> game, vector<int> lastSeen) {
  int limit = floor(nUmps / 2) - d2;
  int vioCounter = 0;
  // for (int t = 0; t < 2 * nUmps; t++) {
  //   cout << lastSeen[t] << " ";
  // }
  // cout << endl;

  // cout << "Last seen team " << game[0] << ": " << lastSeen[game[0] - 1] << endl;

  if (lastSeen[game[0] - 1] < limit) {
    vioCounter++;
  }
  if (lastSeen[game[1] - 1] < limit) {
    vioCounter++;
  }

  return vioCounter;
}
