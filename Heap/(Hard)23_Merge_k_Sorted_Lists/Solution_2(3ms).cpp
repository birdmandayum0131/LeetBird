#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *merged_root = nullptr;
        ListNode **target_node = &merged_root;
        priority_queue<ListNode *, vector<ListNode *>,
                       decltype([](ListNode *a, ListNode *b) { return a->val > b->val; })>
            node_heap;
        for (auto &node : lists)
            if (node != nullptr)
                node_heap.push(node);
        while (node_heap.size() > 0)
        {
            ListNode *node = node_heap.top();
            node_heap.pop();
            *target_node = new ListNode(node->val);
            target_node = &(*target_node)->next;
            if (node->next != nullptr)
                node_heap.push(node->next);
        }
        return merged_root;
    }
};
// ! time complexity O(n), optimize previous solution with heap.
int main(void)
{
    Solution solution;
    // vector<vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode *> lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6)),
    };
    ListNode *merged = solution.mergeKLists(lists);
    while (merged != nullptr)
    {
        cout << merged->val << ", ";
        merged = merged->next;
    }
    cout << "\b\b " << endl;
}