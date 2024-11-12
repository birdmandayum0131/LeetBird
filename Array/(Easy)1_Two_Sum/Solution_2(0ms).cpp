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
        vector<short> index(nums.size());
        iota(index.begin(), index.end(), 0);

        sort(index.begin(), index.end(), [&](short &a, short &b) { return nums[a] < nums[b]; });
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
                return {index[i], index[j]};
            else if (nums[i] + nums[j] > target)
                j--;
            else
                i++;
        }
        return {};
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