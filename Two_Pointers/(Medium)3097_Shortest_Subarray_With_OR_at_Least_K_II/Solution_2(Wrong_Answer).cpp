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
        // int *used_bit = new int[n]();
        int left = 0, right = 0;
        int bitwise_or = 0;
        int shortest_len = n + 1;
        for (right = 0; right < n; right++)
        {
            bitwise_or |= nums[right];
            if (bitwise_or < k)
                continue;
            while (left < right)
            {
                if (bitwise_or - (bitwise_or & nums[left]) < k)
                    break;
                bitwise_or -= bitwise_or & nums[left];
                left++;
            }
            shortest_len = min(shortest_len, right - left + 1);
        }
        if (shortest_len == n + 1)
            return -1;
        return shortest_len;
    }
};
//! Can't just minus the left value, the same bit may be founded in other value in window.
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 2, 32, 21};
    int k = 55;
    int output = solution.minimumSubarrayLength(nums, k);
    cout << output << endl;
}