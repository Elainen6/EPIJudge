#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SearchSmallest(const vector<int>& A) {
  if (A.size() < 2) {
    return A.size() - 1;
  }
  if (A.size() == 2) {
    if (A[0] < A[1]) {
      return 0;
    } else {
      return 1;
    }
  }
  // TODO - you fill in here.
  int left = 0;
  int right = A.size() - 1;
  while(left <= right) {
    int mid = left + ((right - left) / 2);
    if (A[mid] < A[mid + 1] && A[mid] < A[mid - 1]) {
      return mid;
    } else if (A[mid] < A[0]) {
      if (mid == right) return mid;
      right = mid - 1;
    } else {
      
      left = mid + 1;
    }
  }
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "search_shifted_sorted_array.cc",
                         "search_shifted_sorted_array.tsv", &SearchSmallest,
                         DefaultComparator{}, param_names);
}
