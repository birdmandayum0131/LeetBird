#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int start = 0, end = 0;
        int sum = nums[0];
        int maxsum = sum;
        int frontbuffersum = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[start] < 0)
            {
                start++;
                end = start;
                sum = nums[start];
                if (sum > maxsum)
                    maxsum = sum;
                continue;
            }
            frontbuffersum += nums[i];
            if (frontbuffersum > 0)
            {
                end = i;
                sum += frontbuffersum;
                if (sum > maxsum)
                    maxsum = sum;
                frontbuffersum = 0;
            }
            else if (frontbuffersum + sum <= 0 && i < nums.size() - 1)
            {
                start = i + 1;
                end = start;
                sum = nums[start];
                if (sum > maxsum)
                    maxsum = sum;
                frontbuffersum = 0;
                i++;
            }
        }
        return maxsum;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int output = solution.maxSubArray(nums);
    cout << output << endl;
}
