#include <string>
#include <iostream>

#include "test_framework/generic_test.h"
using std::string;
int Evaluate(const string& expression) {
  // TODO - you fill in here.
  std::stack<string> expressionStack;
  int startToFind = 0;
  while(startToFind < expression.size()) {
    int commaPos = expression.find(',', startToFind);
    string expr;
    if (commaPos == std::string::npos) {
      expr = expression.substr(startToFind);
      startToFind = expression.size();
    } else {
     expr = expression.substr(startToFind, commaPos - startToFind);
    startToFind = commaPos + 1;
    }
    if (expr == "+" || expr == "-" || expr == "*" || expr == "/") {
      string operand1 = expressionStack.top();
      //std::cout << "test " << operand1 << std::endl; 
      int64_t ope1 = std::stoll(operand1);
      expressionStack.pop();
      string operand2 = expressionStack.top();
      int64_t ope2 = std::stoll(operand2);
      expressionStack.pop();
      int64_t result;
      if (expr == "+") result = ope2 + ope1;
      if (expr == "-") result = ope2 - ope1;
      if (expr == "*") result = ope2 * ope1;
      if (expr == "/") result = ope2 / ope1;
      expressionStack.push(std::to_string(result));
      //std::cout << "stack: "<< expressionStack
      //std::cout << operand1 << " " << expr << " " << operand2 << " = " << result << std::endl;
    } else {
      expressionStack.push(expr);
    }
  }
  return std::stoi(expressionStack.top());

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"expression"};
  return GenericTestMain(args, "evaluate_rpn.cc", "evaluate_rpn.tsv", &Evaluate,
                         DefaultComparator{}, param_names);
}
