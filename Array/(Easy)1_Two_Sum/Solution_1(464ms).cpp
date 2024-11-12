#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result(2);
        vector<int> cmpNums(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (cmpNums[j] == nums[i])
                {
                    result[0] = j;
                    result[1] = i;
                    return result;
                }
            }
            cmpNums[i] = target - nums[i];
        }
        return result;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> value = solution.twoSum(nums, target);
    for (auto v : value)
        cout << v << ", ";
    cout << "\b\b " << endl;
}