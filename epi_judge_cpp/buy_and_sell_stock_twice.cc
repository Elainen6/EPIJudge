#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
  // TODO - you fill in here.
  // split to first and second subarray
  // first: 0 - j, second: j - n - 1
  //
  double max_total_profit = 0.0;
  vector<double> first_profit;
  double minSoFar = prices[0];
  double max_first_profit = 0.0;
  for (int i = 0; i < prices.size(); i++) {
    minSoFar = std::min(minSoFar, prices[i]);
    first_profit.push_back(std::max(prices[i] - minSoFar, max_first_profit));
  }

  double max_second_profit = 0.0;
  double maxSoFar = prices[prices.size() - 1];
  for (int i = prices.size() - 1; i >= 0; i--) {
    maxSoFar = std::max(maxSoFar, prices[i]);
    max_second_profit = std::max(maxSoFar - prices[i], max_second_profit);
    if (i == 0) {
      max_total_profit = std::max(max_total_profit, max_second_profit);
    } else {
      max_total_profit = std::max(max_total_profit, max_second_profit + first_profit[i - 1]);
    }
    
  }
  return max_total_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
