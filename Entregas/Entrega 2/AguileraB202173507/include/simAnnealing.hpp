#ifndef SIMANNEALING_HPP
#define SEIMANNEALING_HPP

#include "./initialSolution.hpp"

Solution randomSwap(Solution* sol);

Solution simulatedAnnealing(TUP* problem, Solution* initialSol, int initialTemp, float alpha);




#endif