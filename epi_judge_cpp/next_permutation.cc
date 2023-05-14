#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> NextPermutation(vector<int> perm) {
  int i, j;
  for (i = perm.size() - 1; i > 0; i--) {
    if (perm[i] > perm[i - 1]) {
      break;
    }
  }
  if (i == 0) {
    return {};
  }
  //std::cout << "debug";
  for (j = perm.size() - 1; j >= i; j--) {
    if (perm[j] > perm[i - 1]) {
      break;
    }
  }
  //std::cout << "debug";
  //std::cout << "debug" << j << i - 1;
  std::swap(perm[j], perm[i - 1]);
  
  std::reverse(begin(perm) + i, end(perm));
  return perm;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm"};
  return GenericTestMain(args, "next_permutation.cc", "next_permutation.tsv",
                         &NextPermutation, DefaultComparator{}, param_names);
}
