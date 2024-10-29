#include <vector>
#include <tuple>
#include <iostream>
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

        int *max_money = new int[nums.size()];
        max_money[0] = nums[0];
        max_money[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            max_money[i] = max(max_money[i - 2] + nums[i], max_money[i - 1]);
        return max_money[nums.size() - 1];
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {2, 7, 9, 3, 1};
    int output = solution.rob(nums);
    cout << output << endl;
}