#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_euclid(int a, int b) {
  if (b == 0)
    return a;
  int rem = a % b;
  return gcd_euclid(b, rem);
}

/*
  Calculate LCM using Greatest Common Divisor (GCD)
  See https://artofproblemsolving.com/wiki/index.php?title=Least_common_multiple#Using_the_GCD
  LCM(a,b) = a*b / GCD(a,b)
*/
long long lcm_gcd(int a, int b) {
  return (long long) a * b / gcd_euclid(a, b) ;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_gcd(a, b) << std::endl;
  return 0;
}
