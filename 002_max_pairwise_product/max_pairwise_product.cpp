#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  int max_1 = -1;
  int max_2 = -1;
  for (int i = 0; i < n; ++i) {
    if (max_1 == -1)
      max_1 = numbers[i];
    else {
      if (numbers[i] >= max_1) {
        max_2 = max_1;
	max_1 = numbers[i];
      }
      else {
        if (numbers[i] > max_2)
          max_2 = numbers[i];
      }
    }  
  }
  result = (long long)(max_1) * max_2;
  return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
