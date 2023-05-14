#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
bool CheckSymmetric(const unique_ptr<BinaryTreeNode<int>>& subtree0, const unique_ptr<BinaryTreeNode<int>>& subtree1) {
  if (!subtree0 && !subtree1) {
    return true;
  }
  if (subtree0 && subtree1) {
    return (subtree0->data == subtree1->data) && CheckSymmetric(subtree0->left, subtree1->right)
    && CheckSymmetric(subtree0->right, subtree1->left);
  } else {
    return false;
  }
}
bool IsSymmetric(const unique_ptr<BinaryTreeNode<int>>& tree) {
  // TODO - you fill in here.
  return !tree || (CheckSymmetric(tree->left, tree->right));
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_symmetric.cc", "is_tree_symmetric.tsv",
                         &IsSymmetric, DefaultComparator{}, param_names);
}
