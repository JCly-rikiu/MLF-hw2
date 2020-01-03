#include <iostream>
#include <random>
#include <tuple>
#include <vector>

#include "dsm.h"
#include "file.h"

std::vector<std::tuple<double, bool>> generateData(int size) {
  std::vector<std::tuple<double, bool>> data;
  data.reserve(size);

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_real_distribution<> dis(-1.0, 1.0);
  std::uniform_real_distribution<> p(0.0, 1.0);
  for (int i = 0; i < size; i++) {
    double x = dis(random_engine);
    bool y = x >= 0;
    if (p(random_engine) <= 0.2) y = !y;

    data.push_back({x, y});
  }

  return data;
}

void problem1718() {
  int times = 5000;
  int size = 20;
  double Ein = 0.0, Eout = 0.0;
  for (int i = 0; i < times; i++) {
    auto data = generateData(size);
    auto [e, t, s] = trainDSM(data);

    Ein += e;
    Eout += 0.5 + 0.3 * s * (std::abs(t) - 1);
  }
  std::cout << Ein / times << std::endl;
  std::cout << Eout / times << std::endl;
}

void problem1920() {
  int times = 5000;

  auto&& [data, dimension] = parse("data/hw2_train.dat");
  auto&& [test, dimension2] = parse("data/hw2_test.dat");

  double Ein = 0.0, Eout = 0.0;
  for (int i = 0; i < times; i++) {
    double min_error_rate = 1.0;
    double min_theta = 0.0;
    int min_s = 1, min_d = 0;
    for (unsigned int d = 0; d < dimension; d++) {
      std::vector<std::tuple<double, bool>> temp;
      for (auto& [X, y] : data) temp.push_back({X[d], y});

      auto [e, t, s] = trainDSM(temp);
      if (e < min_error_rate) {
        min_error_rate = e;
        min_theta = t;
        min_s = s;
        min_d = d;
      }
    }
    Ein += min_error_rate;

    std::vector<std::tuple<double, bool>> temp;
    for (auto& [X, y] : test) temp.push_back({X[min_d], y});

    Eout += calculateErrorRate(temp, min_theta, min_s);
  }

  std::cout << Ein / times << std::endl;
  std::cout << Eout / times << std::endl;
}

void problem7() {
  int times = 1000;
  int size = 20;
  for (int i = 0; i < times; i++) {
    auto data = generateData(size);
    auto [Ein, t, s] = trainDSM(data);

    double Eout = 0.5 + 0.3 * s * (std::abs(t) - 1);

    std::cout << Ein - Eout << " ";
  }
  std::cout << std::endl;
}

void problem8() {
  int times = 1000;
  int size = 2000;
  for (int i = 0; i < times; i++) {
    auto data = generateData(size);
    auto [Ein, t, s] = trainDSM(data);

    double Eout = 0.5 + 0.3 * s * (std::abs(t) - 1);

    std::cout << Ein - Eout << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Please select the problem!" << std::endl;
    return -1;
  }

  switch (std::stoi(argv[1])) {
    case 7: {
      problem7();
    } break;
    case 8: {
      problem8();
    } break;
  }

  return 0;
}
