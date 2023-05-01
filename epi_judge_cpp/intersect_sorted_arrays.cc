#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
                                     const vector<int>& B) {
  // TODO - you fill in here.
  int a = 0, b = 0;
  vector<int> result;
  while(a < A.size() && b < B.size()) {
    if (A[a] < B[b]) {
      a++;
    } else if (A[a] > B[b]) {
      b++;
    } else {
      if (a == 0 || A[a] != A[a - 1]) {
        //std::cout << A[a] << std::endl;
        result.push_back(A[a]);
        
      }
      a++; b++;
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "B"};
  return GenericTestMain(
      args, "intersect_sorted_arrays.cc", "intersect_sorted_arrays.tsv",
      &IntersectTwoSortedArrays, DefaultComparator{}, param_names);
}
