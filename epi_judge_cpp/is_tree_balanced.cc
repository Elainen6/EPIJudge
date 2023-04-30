#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <unordered_map>
#include <utility>
struct HeightInfo{
  int height;
  bool balanced;
  HeightInfo(int height = 0, bool balanced = true) : height(height), balanced(balanced) {

  }
};

HeightInfo IsBalancedHelper(const unique_ptr<BinaryTreeNode<int>>& tree) {
  if (!tree) {
    return {};
  }

  HeightInfo leftInfo = IsBalancedHelper(tree->left);
  HeightInfo rightInfo = IsBalancedHelper(tree->right);
  int heightRoot = std::max(leftInfo.height, rightInfo.height) + 1;
  bool rootBalanced = leftInfo.balanced && rightInfo.balanced && abs(leftInfo.height - rightInfo.height) < 2;
  return {heightRoot, rootBalanced};
}
bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  if (!tree) {
    return true;
  }
  return IsBalancedHelper(tree).balanced;

}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
