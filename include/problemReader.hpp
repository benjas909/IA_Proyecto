#ifndef PROBLEMREADER_HPP
#define PROBLEMREADER_HPP
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include "./TUP.hpp"

/**
 * @brief Process txt file and extract problem data, generates TUP object
 *
 * @param fileName
 * @return TUP
 */
TUP readProblemFile(string fileName);


#endif
