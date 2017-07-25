#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <array>

using std::vector;
using std::string;
using std::max;
using std::min;

struct MinAndMax_t {
  int min;
  int max;
};

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  long long count_of_numbers = exp.length();
  if (exp.length() % 2 != 0) {
    count_of_numbers += 1;
  }

  // initialize min and max matrices
  //long long min_vals[][] = new long long[count_of_numbers][count_of_numbers];
  std::array<std::array<int, 3>, 3> = new array(3, 3);

  long long i;
  for (i = 0; i < count_of_numbers; ++i) {

  }

  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
