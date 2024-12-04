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
        vector<int> num_index_map(100001); // * 0 for init index+1
        int left = 0, right = 0;
        long long count = 0, max_count = 0;
        while (right < n)
        {
            // * check window is legal
            count += nums[right];
            while (left < num_index_map[nums[right]] || right - left + 1 > k)
            {
                count -= nums[left];
                left++;
            }
            num_index_map[nums[right]] = right + 1;
            if (right - left + 1 == k)
                max_count = max(max_count, count);
            right++;
        }
        return max_count;
    }
};
// ! two pointers solution (O(n))
int main(void)
{
    Solution solution;
    vector<int> nums = {3, 2, 3, 1};
    int k = 3;
    long long result = solution.maximumSubarraySum(nums, k);
    cout << result << endl;
}