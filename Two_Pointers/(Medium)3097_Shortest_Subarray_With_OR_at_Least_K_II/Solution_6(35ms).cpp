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
        int *bit_count = new int[32]();
        int *bit_value = new int[32]();
        for (int i = 0; i < 32; i++)
            bit_value[i] = 1 << i;
        int left = 0, right = 0;
        int bitwise_or = 0;
        int shortest_len = n + 1;
        for (right = 0; right < n; right++)
        {
            bitwise_or |= nums[right];
            for (int i = 0; i < 32; i++)
                if (nums[right] & bit_value[i])
                    bit_count[i]++;
            if (bitwise_or < k)
                continue;
            while (bitwise_or >= k && left <= right)
            {
                for (int i = 0; i < 32; i++)
                {
                    if (nums[left] & bit_value[i])
                    {
                        bit_count[i]--;
                        if (!bit_count[i])
                            bitwise_or -= bit_value[i];
                    }
                }
                left++;
            }
            shortest_len = min(shortest_len, right - left + 2);
        }
        if (shortest_len == n + 1)
            return -1;
        return shortest_len;
    }
};
//! seems it doesn't speed up the result
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    int output = solution.minimumSubarrayLength(nums, k);
    cout << output << endl;
}