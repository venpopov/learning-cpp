#pragma once
#include <iostream>
#include <vector>

namespace utils {

template <typename T>
void print_vector(const std::vector<T> &v) {
  for (const auto &i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

}  // namespace utils
