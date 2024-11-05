#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);

        int n = nums.size();
        vector<vector<int>> max_money(n, vector<int>(2, 0));
        max_money[0][0] = 0;
        max_money[0][1] = nums[0];
        max_money[1][0] = nums[1];
        max_money[1][1] = nums[0];
        for (int i = 2; i < n - 1; i++)
        {
            max_money[i][0] = max(max_money[i - 2][0] + nums[i], max_money[i - 1][0]);
            max_money[i][1] = max(max_money[i - 2][1] + nums[i], max_money[i - 1][1]);
        }
        max_money[n - 1][0] = max(max_money[n - 3][0] + nums[n - 1], max_money[n - 2][0]);
        max_money[n - 1][1] = max(max_money[n - 3][1], max_money[n - 2][1]);
        return max(max_money[n - 1][0], max_money[n - 1][1]);
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {2, 3, 2};
    int output = solution.rob(nums);
    cout << output << endl;
}