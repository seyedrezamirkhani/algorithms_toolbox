#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using std::vector;

class Item {
  public:
    double unit;
    int weight;
    int value;
    Item() {unit = 0.0; weight = 0; value = 0;}
    Item(double _unit, int _weight, int _value) : unit(_unit), weight(_weight), value(_value) {}
};

bool compare_item (Item i,Item j) { return (i.unit < j.unit); }

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  Item f = Item(1.0, 1, 2);
  int size = weights.size();
  std::vector<Item> units(size);
  for (int i = 0; i < size; i++) {
    units.push_back(Item((double)values[i]/weights[i], weights[i], values[i]));    
  }
  // sort units in reverse order
  std::sort(units.begin(), units.end(), compare_item);
  std::reverse(units.begin(), units.end());

  int i = 0;
  while ((i < size) && (capacity > 0)) {
    if (units[i].weight > 0) {
      int take = std::min(units[i].weight, capacity);
      // std::cout << "take : " << take << "units : " << units[i].unit << std::endl;
      value += take * units[i].unit;
      units[i].weight -= take;
      capacity -= take;
    } else {
      ++i;
    }    
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed;
  std::cout.precision(4);
  std::cout << optimal_value << std::endl;
  return 0;
}
