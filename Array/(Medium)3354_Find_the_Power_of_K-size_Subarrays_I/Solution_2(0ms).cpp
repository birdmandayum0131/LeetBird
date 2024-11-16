#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        int n = nums.size();
        vector<int> subarray_powers(n - k + 1);
        queue<int> no_power_start_index;
        for (int i = 1; i < n; i++)
            if (nums[i] != nums[i - 1] + 1)
                no_power_start_index.push(i);

        // * every segment include front element of stack has no power.
        for (int i = k; i <= n; i++)
        {
            // * pop over index
            while (no_power_start_index.size() > 0 && no_power_start_index.front() - 1 < i - k)
                no_power_start_index.pop();
            if (no_power_start_index.size() > 0 && no_power_start_index.front() < i)
                subarray_powers[i - k] = -1;
            else
                subarray_powers[i - k] = nums[i - 1];
        }
        return subarray_powers;
    }
};
// ! Better solution with O(n) time complexity.
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 3, 4};
    int k = 2;
    vector<int> result = solution.resultsArray(nums, k);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << ",";
    cout << "\b " << endl;
}