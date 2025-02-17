#include <numeric>
#include <vector>
#include <iostream>
#include "../lib/utils.hpp"

using std::cout;
using std::vector;
using utils::print_vector;

int main() {
  vector<int> empty_vec;
  vector<int> five_zeros(5);
  vector<int> five_twos(5, 2);
  vector<int> list_init = {1, 2, 3, 4, 5};
  vector<int> uniform_init{1, 2, 3, 4, 5};
  auto template_deduce = vector{1, 2, 3, 4, 5};

  // a sequence of integers is cumbersome - generate a vector of 0s of desired
  // length, then apply iota function
  vector<int> seq_vec(10);
  std::iota(seq_vec.begin(), seq_vec.end(), 1);

  // not what I thought - it just begins the sequence from 2;
  vector<int> seq_vec_by2(10);
  std::iota(seq_vec_by2.begin(), seq_vec_by2.end(), 2);

  cout << "Vector contents\n";
  print_vector(empty_vec);
  print_vector(five_zeros);
  print_vector(five_twos);
  print_vector(list_init);
  print_vector(uniform_init);
  print_vector(template_deduce);
  print_vector(seq_vec);
  print_vector(seq_vec_by2);

  cout << "\nVector capacities\n";
  cout << empty_vec.capacity() << '\n';
  cout << five_zeros.capacity() << '\n';
  cout << five_twos.capacity() << '\n';
  cout << list_init.capacity() << '\n';
  cout << uniform_init.capacity() << '\n';
  cout << template_deduce.capacity() << '\n';
  cout << seq_vec.capacity() << '\n';

  return 0;
}
