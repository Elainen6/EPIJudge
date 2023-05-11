#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.
  /*double maxDiff = 0.0;
  for (int i = 0; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      if(prices[i] < prices[j]) {
        maxDiff = std::max(prices[j] - prices[i], maxDiff);
      }
    }
  }
  return maxDiff;*/
  /*int firstSub = prices.size() / 2;
  int secondSub = firstSub + 1;
  double firstProfit = 0.0;
  for (int i = 0; i <= firstSub; i++) {
    for (int j = i + 1; j <= firstSub; j++) {
      if(prices[i] < prices[j]) {
        firstProfit = std::max(prices[j] - prices[i], firstProfit);
      }
    }
  }
  double secondProfit = 0.0;
  for (int i = secondSub; i < prices.size(); i++) {
    for (int j = i + 1; j < prices.size(); j++) {
      if(prices[i] < prices[j]) {
        secondProfit = std::max(prices[j] - prices[i], secondProfit);
      }
    }
  }
  double firstMin = *std::min_element(begin(prices), begin(prices) + firstSub + 1);
  double secondMax = *std::max_element(begin(prices) + firstSub + 1, end(prices));
  return std::max(std::max(firstProfit, secondProfit), secondMax - firstMin);*/

  double result = 0.0;
  double minSoFar = prices[0];
  for (int i = 0; i < prices.size(); i++) {
    if (prices[i] < minSoFar) {
      minSoFar = prices[i];
    } else {
      result = std::max(result, prices[i] - minSoFar);
    }
  }
  return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
