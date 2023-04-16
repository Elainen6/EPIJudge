#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  /*short res = 0;
  while (x) {
    auto mask = 1;
    if ((mask & x) == 1) {
      res++;
    }
    x = x >> 1;
  }
  if (res % 2) {
    return 1;
  } else {
    return 0;
  }*/
  short res = 0;
  while(x) {
    x = x & (x - 1);
    res++;
  }
  if (res % 2) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
