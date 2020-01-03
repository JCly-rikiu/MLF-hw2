#include "dsm.h"

double calculateErrorRate(const std::vector<std::tuple<double, bool>>& data,
                          double theta, int s) {
  int error_count = 0;
  for (auto& [x, y] : data) {
    if ((s * (x - theta) >= 0) != y) {
      error_count++;
    }
  }

  return static_cast<double>(error_count) / data.size();
}

std::tuple<double, double, int> trainDSM(
    std::vector<std::tuple<double, bool>>& data) {
  std::sort(data.begin(), data.end());

  double min_error_rate = 1.0;
  double min_theta;
  int min_s;
  double last = -1.0;

  for (decltype(data.size()) i = 0; i < data.size() + 1; i++) {
    double x = 1.0;
    bool y = true;
    if (i < data.size())
      std::tie(x, y) = data[i];

    double theta = (last + x) / 2;
    double error_rate = calculateErrorRate(data, theta, 1);
    if (min_error_rate > error_rate) {
      min_error_rate = error_rate;
      min_theta = theta;
      min_s = 1;
    }
    error_rate = calculateErrorRate(data, theta, -1);
    if (min_error_rate > error_rate) {
      min_error_rate = error_rate;
      min_theta = theta;
      min_s = -1;
    }

    last = x;
  }

  return {min_error_rate, min_theta, min_s};
}
