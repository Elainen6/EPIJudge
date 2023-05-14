#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  if (n < 2) {
    return {};
  }
  vector<int> primes;
  std::deque<bool> is_primes(n + 1, true);
  is_primes[0] = false;
  is_primes[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_primes[i]) {
      primes.push_back(i);
    }
    for (int j = i * 2; j <= n; j += i) {
      is_primes[j] = false;
    }
  }
  return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
