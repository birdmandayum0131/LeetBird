#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int end = 0;
        int sum = 0;
        int minCount = nums.size() + 1;

        while (end < nums.size())
        {
            sum += nums[end];
            while (sum - nums[start] >= target)
            {
                sum -= nums[start];
                start++;
            }
            if (sum >= target && (end - start + 1) < minCount)
                minCount = (end - start + 1);
            if (minCount == 1)
                break;
            end++;
        }
        if (minCount > nums.size())
            return 0;
        else
            return minCount;
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