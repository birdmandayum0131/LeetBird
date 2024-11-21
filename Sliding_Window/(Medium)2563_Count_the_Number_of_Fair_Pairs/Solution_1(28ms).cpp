#include <iostream>
#include <map>
#include <numeric>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int less_than_upper_count = 0;
        for (int i = 0, j = n - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > upper)
                j--;
            less_than_upper_count += j - i;
        }
        int less_than_lower_count = 0;
        for (int i = 0, j = n - 1; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > lower - 1)
                j--;
            less_than_lower_count += j - i;
        }
        return less_than_upper_count - less_than_lower_count;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    long long value = solution.countFairPairs(nums, lower, upper);
    cout << value << endl;
}