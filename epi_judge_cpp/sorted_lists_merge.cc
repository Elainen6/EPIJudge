#include "list_node.h"
#include "test_framework/generic_test.h"
void appendNode(shared_ptr<ListNode<int>> *l, shared_ptr<ListNode<int>> *forward) {
  (*forward)->next = *l;
  *forward = (*forward) ->next;
  *l = (*l)->next;
}
shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L1,
                                              shared_ptr<ListNode<int>> L2) {
  // TODO - you fill in here.
  shared_ptr<ListNode<int>> dummyHead(new ListNode<int>);
  auto forward = dummyHead;
  while(L1 && L2) {
    L1->data > L2->data ? appendNode(&L2, &forward) : appendNode(&L1, &forward);
    //forward = forward->next;
  }

  if (L1) {
    forward->next = L1;
    //std::cout << "test" << std::endl;
  }
  if (L2) {
    forward->next = L2;
  }
  return dummyHead->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L1", "L2"};
  return GenericTestMain(args, "sorted_lists_merge.cc",
                         "sorted_lists_merge.tsv", &MergeTwoSortedLists,
                         DefaultComparator{}, param_names);
}
