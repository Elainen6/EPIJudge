#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <unordered_map>
#include <utility>

void getHeight(const unique_ptr<BinaryTreeNode<int>>& tree, std::unordered_map<unique_ptr<BinaryTreeNode<int>>&, int>& heightResult) {
  if (tree != nullptr) {
    if (tree->left == nullptr && tree->right == nullptr) {
      heightResult.emplace(std::move(tree), 1);
    } else {
      getHeight(tree->left, heightResult);
      getHeight(tree->right, heightResult);
      heightResult.emplace(std::move(tree), std::max(heightResult[tree->left], heightResult[tree->right]) + 1);
    }
  } 
}
bool IsBalanced(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  std::unordered_map<unique_ptr<BinaryTreeNode<int>>&, int> heightMap;
  if (tree) {
    getHeight(tree->left, heightMap);
    getHeight(tree->right, heightMap);
    heightMap.emplace(std::move(tree),std::max(heightMap[tree->left], heightMap[tree->right]) + 1);
  }


}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_balanced.cc", "is_tree_balanced.tsv",
                         &IsBalanced, DefaultComparator{}, param_names);
}
