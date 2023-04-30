#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
void addTwoArrays(vector<int>& result, vector<int> const& intermediate) {
  if (result.empty()) {
    result = intermediate;
    return;
  }

  vector<int> helperStore;
  int resultPos = result.size() - 1;
  int intermediatePos = intermediate.size() - 1;
  int carry = 0;
  while(resultPos >= 0 || intermediatePos >= 0) {
    int sum;
    if (resultPos >= 0 && intermediatePos >= 0) {
      sum = result[resultPos] + intermediate[intermediatePos] + carry;
    } else if (resultPos >= 0 && intermediatePos < 0) {
      sum = result[resultPos] + carry;
    } else {
      sum = intermediate[intermediatePos] + carry;
    }
    carry = sum / 10;
    sum %= 10; 
    helperStore.insert(begin(helperStore), sum);
    resultPos--;
    intermediatePos--;
  }
  if (carry != 0) {
    helperStore.insert(begin(helperStore), carry);
  }
  result = helperStore;
  return;
}
vector<int> Multiply(vector<int> num1, vector<int> num2) {
  if (num1.empty() || num2.empty()) {
    return {};
  }
  int sign = 1;
  // TODO - you fill in here.
  if (num1[0] < 0) {
    sign *= -1;
    num1[0] *= -1;
  }
  if (num2[0] < 0) {
    sign *= -1;
    num2[0] *= -1;
  }
  vector<int> result;
  // multiply every digit of num2 with last digit of num1, then the second last digit of num1, multiplr by 10, add
  // intermediate result;
  for (int i = num1.size() - 1; i >= 0; i--) {
    vector<int> intermediate;
    int carry = 0;
    for (int j = num2.size() - 1; j >= 0; j--) {
      int multiplyResult = num1[i] * num2[j] + carry;
      carry = multiplyResult / 10;
      int multiplyDigit = multiplyResult % 10;
      intermediate.insert(begin(intermediate), multiplyDigit);
    }
    if (carry != 0) {
      intermediate.insert(begin(intermediate), carry);
    }
    int appendZero = num1.size() - 1 - i;
    for (int i = 0; i < appendZero; i++) {
      intermediate.push_back(0);
    }
    // add result with intermediate and put the adding result in result
    addTwoArrays(result, intermediate);
  }
  result[0] *= sign;
  auto leadingZero = find_if(begin(result), end(result) - 1, [](auto i){return i != 0;});
  result.erase(begin(result), leadingZero);
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
