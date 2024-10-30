#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> canReachEnd(n, false);
        canReachEnd.back() = true;
        for (int i = n - 2; i >= 0; i--)
        {
            bool canReach = false;
            for (int j = i + 1; j <= min(i + nums[i], n - 1); j++)
            {
                canReach = canReach || canReachEnd[j];
                if (canReach)
                    break;
            }
            canReachEnd[i] = canReach;
        }

        return canReachEnd[0];
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    bool output = solution.canJump(nums);
    cout << output << endl;
}
