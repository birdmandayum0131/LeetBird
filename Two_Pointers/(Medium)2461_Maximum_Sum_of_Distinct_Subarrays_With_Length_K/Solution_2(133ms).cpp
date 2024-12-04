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
        vector<int> num_map(100001);
        vector<long long> dp_sum(n - k + 1);
        int start = 0;
        long long count = 0;
        long long max_sum = 0;
        int distinct_count = 0;
        while (start <= n - k)
        {
            int next = start + 1;
            int i = start;
            if (start > 0 && dp_sum[start - 1] > 0)
            {
                num_map[nums[start - 1]] = 0;
                i = start + k - 1;
                distinct_count--;
                count -= nums[start - 1];
            }
            else
            {
                count = 0;
                distinct_count = 0;
                num_map = vector<int>(100001);
            }
            while (i < start + k)
            {
                if (num_map[nums[i]] > 0)
                {
                    next = num_map[nums[i]];
                    break;
                }
                count += nums[i];
                num_map[nums[i]] = i + 1;
                distinct_count++;
                i++;
            }
            if (distinct_count == k)
            {
                max_sum = max(count, max_sum);
                dp_sum[start] = count;
            }
            start = next;
        }
        return max_sum;
    }
};
// ! time complexity O(n*k) but speed up with dp
int main(void)
{
    Solution solution;
    vector<int> nums = {3, 2, 3, 1};
    int k = 3;
    long long result = solution.maximumSubarraySum(nums, k);
    cout << result << endl;
}