#include <stack>
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = l1->val + l2->val;
        ListNode *result = new ListNode(sum % 10);
        ListNode *tmp = result;
        sum /= 10;
        do
        {
            if (l1 != nullptr && l1->next != nullptr)
            {
                l1 = l1->next;
                sum += l1->val;
            }
            else
                l1 = nullptr;
            if (l2 != nullptr && l2->next != nullptr)
            {
                l2 = l2->next;
                sum += l2->val;
            }
            else
                l2 = nullptr;

            if (sum > 0 || l1 != nullptr || l2 != nullptr)
            {
                tmp->next = new ListNode(sum % 10);
                tmp = tmp->next;
                sum /= 10;
            }
        } while (l1 != nullptr || l2 != nullptr);
        return result;
    }
};
int main(void)
{
    Solution solution;

    ListNode *tmp = nullptr;

    // * fill L1 list
    int l1[] = {1, 6, 0, 3, 3, 6, 7, 2, 0, 1};
    ListNode *l1Start = new ListNode(l1[0]);
    tmp = l1Start;
    for (int i = 1; i < *(&l1 + 1) - l1; i++)
    {
        tmp->next = new ListNode(l1[i]);
        tmp = tmp->next;
    }

    // * fill L2 list
    int l2[] = {6, 3, 0, 8, 9, 6, 6, 9, 6, 1};
    ListNode *l2Start = new ListNode(l2[0]);
    tmp = l2Start;
    for (int i = 1; i < *(&l2 + 1) - l2; i++)
    {
        tmp->next = new ListNode(l2[i]);
        tmp = tmp->next;
    }

    ListNode *result = solution.addTwoNumbers(l1Start, l2Start);
    while (result != nullptr)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
}