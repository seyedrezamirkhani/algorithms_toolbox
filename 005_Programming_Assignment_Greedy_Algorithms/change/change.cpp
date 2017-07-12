#include <iostream>

int get_change(int m) {
  //write your code here
  int coins[] = {10,5,1};
  int count = 0;
  int i = 0;

  while (i < 3) {
    if (m >= coins[i]) {
      m -= coins[i];
      count += 1;
    } else {
      ++i;
    }   
  }
  
  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
