#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        vector<int> sums(nums.size(), 0);
        vector<int> counts(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (sums[j] < target)
                {
                    sums[j] += nums[i];
                    counts[j]++;
                }
            }
        }
        int min = nums.size() + 1;
        for (int i = 0; i < sums.size(); i++)
        {
            if (sums[i] >= target)
            {
                if (counts[i] < min)
                    min = counts[i];
            }
        }
        if (min > nums.size())
            return 0;
        else
            return min;
    }
};
int main(void)
{
    Solution solution;
    int target = 213;
    vector<int> numbers{12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12};
    int result = solution.minSubArrayLen(target, numbers);
    cout << result << endl;
}