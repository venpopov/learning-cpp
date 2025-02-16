#include <algorithm>
#include <iostream>
#include <random>

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

  for (auto item : flips) {
    std::cout << item << ' ';
  }
  std::cout << '\n';
  return 0;
}
