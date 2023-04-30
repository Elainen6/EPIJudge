#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

int SearchFirstOfK1(const vector<int>& A, int k) {
  // TODO - you fill in here.
  if (A.empty()) {
    return -1;
  }
  auto target = std::lower_bound(begin(A), end(A), k);
  int num = *target;
  if (num == k) {
    return target - begin(A);
  }
  return -1;
}
int SearchFirstOfK(const vector<int>& A, int k) {
  // TODO - you fill in here.
  int left = 0;
  int right = A.size() - 1;
  int resultIndex = -1;
  while(left <= right) {
    int mid = left + ((right - left) / 2);
    if (A[mid] < k) {
      left = mid + 1;
    } else if (A[mid] == k) {
      resultIndex = mid;
      right = mid - 1;
    } else {
      right = mid - 1;
    }
  }
  return resultIndex;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "k"};
  return GenericTestMain(args, "search_first_key.cc", "search_first_key.tsv",
                         &SearchFirstOfK, DefaultComparator{}, param_names);
}
