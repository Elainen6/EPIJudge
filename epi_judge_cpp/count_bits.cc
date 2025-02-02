#include "test_framework/generic_test.h"

short CountBits(unsigned int x) {
  // TODO - you fill in here.
  // unsigned int is 32 bits
  // short is 16 bits
  // shift and mask 
  short res = 0;
  while (x) {
    auto mask = 0x00000001;
    if ((mask & x) == 1) {
      res++;
    }
    x = x >> 1;
  }
  return res;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
