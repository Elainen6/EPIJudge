#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
void ApplyPermutation(vector<int> perm, vector<int>* A_ptr) {
  vector<int>& vec = *A_ptr;
  for (int i = 0; i < vec.size(); i++) {
    while(i != perm[i]) {
      std::swap(vec[i], vec[perm[i]]);
      std::swap(perm[i], perm[perm[i]]);
    }
  }
  return;
}
vector<int> ApplyPermutationWrapper(const vector<int>& perm, vector<int> A) {
  ApplyPermutation(perm, &A);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"perm", "A"};
  return GenericTestMain(args, "apply_permutation.cc", "apply_permutation.tsv",
                         &ApplyPermutationWrapper, DefaultComparator{},
                         param_names);
}
