#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode* end = nullptr;
        ListNode* reverse_head;
        while(head!=nullptr){
            reverse_head = new ListNode(head->val);
            reverse_head->next = end;
            end = reverse_head;
            head = head->next;
        }
        return reverse_head;
    }
};
int main(void)
{
    Solution solution;
    vector<int> linked_list = {1, 2, 3, 4, 5};
    ListNode *head;
    ListNode **target = &head;
    for (auto node : linked_list)
    {
        *target = new ListNode(node);
        target = &(*target)->next;
    }

    ListNode *reverse_head = solution.reverseList(head);
    while (reverse_head != nullptr)
    {
        cout << reverse_head->val << ", ";
        reverse_head = reverse_head->next;
    }
    cout << "\b\b ";
}