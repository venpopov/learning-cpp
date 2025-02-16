#include <algorithm>
#include <iostream>
#include <random>
#include "../lib/utils.hpp"

auto coin() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int> dist{0, 1};
  return dist(gen);
}

int main() {
  std::cout << "How many flips?\n";

  int n;
  std::cin >> n;  // ignoring input validation for now

  std::vector<int> flips(n);
  std::generate(flips.begin(), flips.end(), coin);

  utils::print_vector(flips);

  return 0;
}
