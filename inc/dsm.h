#ifndef _DSM
#define _DSM

#include <vector>
#include <tuple>
#include <algorithm>

double calculateErrorRate(const std::vector<std::tuple<double, bool>>&, double, int);
std::tuple<double, double, int> trainDSM(std::vector<std::tuple<double, bool>>&);

#endif
