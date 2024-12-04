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
        int same_bits = nums[0] & k;
        int diff_bits = nums[0] - same_bits;
        int diff_bits_len = 0;
        while (1 << diff_bits_len <= diff_bits)
            diff_bits_len++;
        used_bit[0] = same_bits | (((1 << diff_bits_len) - 1) & k);

        //* right first then left
        for (int right = 1; right < n; right++)
        {
            if(nums[right] == nums[left])
            {
                used_bit[right] = used_bit[left];
                left++;
                continue;
            }

            //* move right to current
            int same_bits = nums[right] & k;
            int diff_bits = nums[right] - same_bits;
            int diff_bits_len = 0;
            while (1 << diff_bits_len <= diff_bits)
                diff_bits_len++;
            used_bit[right] = same_bits | (((1 << diff_bits_len) - 1) & k);

            //* update window
            for (int j = left; j < right; j++)
                used_bit[j] &= ~used_bit[right];

            //* move left
            while (!used_bit[left] && left < right)
                left++;

            bitwise_or |= nums[right];

            if (bitwise_or >= k && shortest_len > right - left + 1)
                shortest_len = right - left + 1;
        }

        if (shortest_len == n + 1)
            return -1;
        else
            return shortest_len;
    }
};
//! O(n^2) in worst case.
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4};
    int k = 6;
    int output = solution.minimumSubarrayLength(nums, k);
    cout << output << endl;
}