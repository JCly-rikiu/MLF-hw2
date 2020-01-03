#ifndef _FILE
#define _FILE

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

std::tuple<std::vector<std::tuple<std::vector<double>, bool>>, unsigned int> parse(std::string&&);

#endif
