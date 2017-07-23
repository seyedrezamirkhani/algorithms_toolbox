#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct majority_t {
    int m; // majority element
    size_t k; // multiplicity of m; zero => no majority element

    majority_t(): m(0), k(0) {}
    majority_t(int m_,size_t k_): m(m_), k(k_) {}

    operator bool() const { return k>0; }
};

static majority_t no_majority;

size_t multiplicity(int x,const int *arr,size_t n) {
    if (n==0) return 0;
    else if (n==1) return arr[0]==x?1:0;

    size_t r=n/2;
    return multiplicity(x,arr,r)+multiplicity(x,arr+r,n-r);
}

majority_t majority(const int *arr,size_t n) {
    if (n==0) return no_majority;
    else if (n==1) return majority_t(arr[0],1);

    size_t r=n/2;
    majority_t left=majority(arr,r);
    if (left) {
        left.k+=multiplicity(left.m,arr+r,n-r);
        if (left.k>r) return left;
    }

    majority_t right=majority(arr+r,n-r);
    if (right) {
        right.k+=multiplicity(right.m,arr,r);
        if (right.k>r) return right;
    }

    return no_majority;
}

// https://stackoverflow.com/questions/28957303/divide-and-conquer-algorithm-for-finding-the-majority-element

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  majority_t res = majority(const_cast<int*>(a.data()), a.size());
  std::cout << res << std::endl;
}
