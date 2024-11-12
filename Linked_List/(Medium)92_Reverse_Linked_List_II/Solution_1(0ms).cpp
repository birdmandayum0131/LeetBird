#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        stack<ListNode *> reverse_nodes; // * use stack to store reverse node
        queue<ListNode *> forward_nodes; // * use queue to store forward node
        vector<bool> is_reverse; // * record reverse index (can be extend to multiple reverse section scenario)

        ListNode *prev_head = new ListNode(); // * fake node;
        ListNode *prev_node = prev_head;
        ListNode *current_node;

        // * index the nodes
        for (int i = 1; head != nullptr; i++)
        {
            ListNode *node = new ListNode(head->val);
            if (i >= left && i <= right)
            {
                is_reverse.push_back(true);
                reverse_nodes.push(node);
            }
            else
            {
                is_reverse.push_back(false);
                forward_nodes.push(node);
            }
            head = head->next;
        }

        for (auto node_reverse : is_reverse)
        {
            if (node_reverse)
            {
                current_node = reverse_nodes.top();
                reverse_nodes.pop();
            }
            else
            {
                current_node = forward_nodes.front();
                forward_nodes.pop();
            }
            prev_node->next = current_node;
            prev_node = current_node;
        }
        return prev_head->next;
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
    ListNode *print_head = head;
    while (print_head != nullptr)
    {
        cout << print_head->val << ", ";
        print_head = print_head->next;
    }
    cout << "\b\b " << endl;

    int left = 2, right = 4;
    ListNode *reverse_head = solution.reverseBetween(head, left, right);
    while (reverse_head != nullptr)
    {
        cout << reverse_head->val << ", ";
        reverse_head = reverse_head->next;
    }
    cout << "\b\b " << endl;
}