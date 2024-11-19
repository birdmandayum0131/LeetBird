#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int countValidSelections(vector<int> &nums)
    {
        int n = nums.size();
        int valid_selections = 0;
        int sum = 0;
        int current_sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        for (int i = 0; i < n; i++)
        {
            current_sum += nums[i];
            if (nums[i] == 0)
            {
                if (current_sum * 2 == sum)
                    valid_selections += 2;
                else if (abs(current_sum * 2 - sum) == 1)
                    valid_selections += 1;
            }
        }
        return valid_selections;
    }
};
// ! Better solution with O(n) time complexity.
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 3, 4};
    int result = solution.countValidSelections(nums);
    cout << result << endl;
}