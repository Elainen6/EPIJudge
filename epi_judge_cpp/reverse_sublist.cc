#include "list_node.h"
#include "test_framework/generic_test.h"

shared_ptr<ListNode<int>> ReverseSublist(shared_ptr<ListNode<int>> L, int start,
                                         int finish) {
  
  // TODO - you fill in here.
  /*if (!L) {
    return nullptr;
  }
  shared_ptr<ListNode<int>> prev = nullptr;
  auto cur = L;
  int i = 1;
  while(start > 1) {
    prev = cur;
    cur = cur->next;
    start--;
    finish--;
  }
  auto con = prev;
  auto tail = cur;

  shared_ptr<ListNode<int>> third = nullptr;
  while(finish > 0) {
    third = cur->next;
    cur->next = prev;
    prev = cur;
    cur = third;
    finish--;
    i++;
  }

  if (con != nullptr) {
    con->next = prev;
  } else {
    L = prev;
  }
  tail->next = cur;
  return nullptr;*/
  auto dummy_head = make_shared<ListNode<int>>(ListNode<int>{0, L});
  auto sublist_head = dummy_head;
  int k = 1;
  while(k < start) {
    k++;
    sublist_head = sublist_head->next;
  }
  auto sublist_iter = sublist_head->next;
  while(start++ < finish) {
    auto temp = sublist_iter->next;
    sublist_iter->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head ->next = temp;
  }
  return dummy_head->next;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"L", "start", "finish"};
  return GenericTestMain(args, "reverse_sublist.cc", "reverse_sublist.tsv",
                         &ReverseSublist, DefaultComparator{}, param_names);
}
