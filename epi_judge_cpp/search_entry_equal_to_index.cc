#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"
using std::vector;

int SearchEntryEqualToItsIndex(const vector<int>& A) {
  // TODO - you fill in here.
  int left = 0;
  int right = A.size() - 1;
  int resultIndex = -1;
  while(left <= right) {
    int mid = left + ((right - left) / 2);
    if (A[mid] < mid) {
      left = mid + 1;
    } else if (A[mid] == mid) {
      resultIndex = mid;
      return resultIndex;
    } else {
      right = mid - 1;
    }
  }

  return resultIndex;
}
void SearchEntryEqualToItsIndexWrapper(TimedExecutor& executor,
                                       const vector<int>& A) {
  int result = executor.Run([&] { return SearchEntryEqualToItsIndex(A); });

  if (result != -1) {
    if (A[result] != result) {
      throw TestFailure("Entry does not equal to its index");
    }
  } else {
    for (int i = 0; i < A.size(); ++i) {
      if (A[i] == i) {
        throw TestFailure("There are entries which equal to its index");
      }
    }
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "search_entry_equal_to_index.cc", "search_entry_equal_to_index.tsv",
      &SearchEntryEqualToItsIndexWrapper, DefaultComparator{}, param_names);
}
