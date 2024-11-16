#include <iostream>
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
        vector<int> power(n - k + 1);
        bool is_asc = true;
        for (int i = 1; i < k; i++)
            is_asc = is_asc && nums[i] == nums[i - 1] + 1;
        power[0] = is_asc ? nums[k - 1] : -1;
        for (int i = 1; i < n - k + 1; i++)
        {
            if (power[i - 1] > 0)
                power[i] = (nums[k - 1 + i] == nums[k - 2 + i] + 1) ? nums[k - 1 + i] : -1;
            else
            {
                bool is_asc = true;
                for (int j = i + 1; j < k + i; j++)
                    is_asc = is_asc && nums[j] == nums[j - 1] + 1;
                power[i] = is_asc ? nums[k + i - 1] : -1;
            }
        }
        return power;
    }
};
// ! bad solution with O(n*k) time complexity but still work.
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