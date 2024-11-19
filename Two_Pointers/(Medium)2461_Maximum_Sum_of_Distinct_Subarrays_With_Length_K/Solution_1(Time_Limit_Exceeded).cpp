#include <iostream>
#include <map>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<bool> num_map(n + 1);
        int start = 0;
        long long count = 0;
        long long max_sum = 0;
        while (start <= n - k)
        {
            count = 0;
            int next = start + 1;
            int distinct_count = 0;
            for (int i = start; i < start + k; i++)
            {
                if (num_map[nums[i]])
                {
                    next = i;
                    num_map = vector<bool>(n + 1);
                    break;
                }
                count += nums[i];
                num_map[nums[i]] = true;
                distinct_count++;
            }
            start = next;
            if (distinct_count == k)
                max_sum = max(count, max_sum);
        }
        return max_sum;
    }
};
// ! time complexity O(n*k)
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
    int k = 3;
    long long result = solution.maximumSubarraySum(nums, k);
    cout << result << endl;
}