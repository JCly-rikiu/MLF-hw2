#include "file.h"

std::tuple<std::vector<std::tuple<std::vector<double>, bool>>, unsigned int> parse(
    std::string&& filename) {
  std::vector<std::tuple<std::vector<double>, bool>> data;
  unsigned int dimension;

  std::string line;
  std::ifstream file(filename);
  if (!file.is_open()) std::cerr << "Error opening file" << std::endl;
  while (std::getline(file, line)) {
    std::istringstream line_stream(line);
    double d;
    std::vector<double> X;
    while (line_stream >> d) X.push_back(d);

    bool y = static_cast<int>(X.back()) == 1;
    X.pop_back();
    dimension = X.size();

    data.push_back({X, y});
  }

  return {data, dimension};
}
