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
        vector<int> candidateStack;
        int farest = 0;
        candidateStack.push_back(0);
        while (candidateStack.size() > 0)
        {
            int target = candidateStack.back();
            candidateStack.pop_back();
            int far = nums[target] + target;
            if (far >= n - 1)
                farest = n - 1;
            if (farest == n - 1)
                break;
            if (far > farest)
            {
                for (int i = farest + 1; i <= nums[target] + target; i++)
                    candidateStack.push_back(i);
                farest = far;
            }
        }

        return farest == n - 1;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {3, 2, 1, 0, 4};
    bool output = solution.canJump(nums);
    cout << output << endl;
}
