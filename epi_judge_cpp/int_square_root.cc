#include "test_framework/generic_test.h"

int SquareRoot(int k) {
  // TODO - you fill in here.
  int left = 0; int right = k;
  while(left <= right) {
    int64_t mid = left + ((right - left) / 2);
    int64_t sqaure = mid * mid;
    if (sqaure <= k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return left - 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"k"};
  return GenericTestMain(args, "int_square_root.cc", "int_square_root.tsv",
                         &SquareRoot, DefaultComparator{}, param_names);
}
