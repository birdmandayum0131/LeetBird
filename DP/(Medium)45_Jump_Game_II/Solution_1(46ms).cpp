#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int jump(vector<int> &nums)
    {
        vector<int> shortJump(nums.size());
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > 0)
            {
                if (i + nums[i] + 1 < nums.size())
                    shortJump[i] = *min_element(shortJump.begin() + i + 1,
                                                shortJump.begin() + i + nums[i] + 1) +
                                   1;
                else
                    shortJump[i] = *min_element(shortJump.begin() + i + 1, shortJump.end()) + 1;
            }
            else
            {
                shortJump[i] = nums.size();
            }
        }
        return shortJump[0];
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {2, 3, 0, 1, 4};
    int output = solution.jump(nums);
    cout << output << endl;
}