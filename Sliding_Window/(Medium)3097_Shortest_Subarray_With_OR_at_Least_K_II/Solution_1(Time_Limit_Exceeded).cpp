#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int *used_bit = new int[n]();
        int left = 0, right = 0;
        int bitwise_or = nums[0];
        int shortest_len = n + 1;
        if (bitwise_or >= k)
            return 1;

        stack<char> bit_stack;
        if (!nums[0])
            used_bit[0] = 0;
        else
        {
            int i = 0;
            while (nums[0] > 0)
            {
                if (nums[0] & 1)
                    bit_stack.push(i);
                i++;
                nums[0] >>= 1;
            }
            while (bit_stack.size())
            {
                if (k & 1 << bit_stack.top())
                    used_bit[0] |= 1 << bit_stack.top();
                else
                {
                    used_bit[0] |= k & ((1 << bit_stack.top()) - 1);
                    bit_stack = stack<char>();
                    break;
                }
                bit_stack.pop();
            }
        }
        //* right first then left
        for (int right = 1; right < n; right++)
        {
            bitwise_or |= nums[right];

            //* move right to current
            if (!nums[right])
                used_bit[right] = 0;
            else
            {
                int i = 0;
                while (nums[right] > 0)
                {
                    if (nums[right] & 1)
                        bit_stack.push(i);
                    i++;
                    nums[right] >>= 1;
                }
                while (bit_stack.size())
                {
                    if (k & 1 << bit_stack.top())
                        used_bit[right] |= 1 << bit_stack.top();
                    else
                    {
                        used_bit[right] |= k & ((1 << bit_stack.top()) - 1);
                        bit_stack = stack<char>();
                        break;
                    }
                    bit_stack.pop();
                }
            }

            //* update window
            for (int j = left; j < right; j++)
                used_bit[j] &= ~used_bit[right];

            //* move left
            while (!used_bit[left] && left < right)
                left++;

            if (bitwise_or >= k && shortest_len > right - left + 1)
                shortest_len = right - left + 1;
        }

        if (shortest_len == n + 1)
            return -1;
        else
            return shortest_len;
    }
};
//! I thought the problem is on stack, but that's not the critical point.
int main(void)
{
    Solution solution;
    vector<int> nums = {5, 1, 32, 86, 2};
    int k = 117;
    int output = solution.minimumSubarrayLength(nums, k);
    cout << output << endl;
}