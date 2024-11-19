#include <iostream>
#include <map>
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
        vector<ListNode *> targets = lists;
        bool atleast_one_node = true;
        while (atleast_one_node)
        {
            ListNode **min_target = nullptr;
            atleast_one_node = false;
            for (auto &target : targets)
                if (target != nullptr && (min_target == nullptr || target->val < (*min_target)->val))
                    min_target = &target;

            atleast_one_node = min_target != nullptr;
            if (atleast_one_node)
            {
                *target_node = new ListNode((*min_target)->val);
                target_node = &((*target_node)->next);
                (*min_target) = (*min_target)->next;
            }
        }
        return merged_root;
    }
};
// ! time complexity O(n*k), can optimize with heap.
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