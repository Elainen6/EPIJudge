#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

vector<int> PlusOne(vector<int> A) {
  if (A.empty()) {
    return {1};
  }
  // TODO - you fill in here.
  vector<int> result(A);
  int pos = A.size() - 1;
  int plusOne = A[pos] + 1;
  result[pos] = plusOne % 10;
  int carry = plusOne / 10;

  while (pos > 0 && carry != 0) {
    pos--;
    plusOne = result[pos] + carry;
    result[pos] = plusOne % 10;   
    carry = plusOne / 10;
  }
  if (pos == 0 && carry != 0) {
    result.insert(begin(result), carry);
  } 
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
