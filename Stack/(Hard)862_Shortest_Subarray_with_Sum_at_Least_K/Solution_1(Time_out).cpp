#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> count_nums(n);
        long long count = 0;
        int min_len = n + 1;
        for (int i = 0; i < n; i++)
        {
            count += nums[i];
            if (count >= 0)
            {
                if (count >= k)
                {
                    for (int j = 1; j < min_len && i >= j; j++)
                    {
                        if (count - count_nums[i - j] >= k)
                            min_len = min(min_len, j);
                        if (min_len == 1)
                            return 1;
                    }
                    min_len = min(min_len, i + 1);
                }
                count_nums[i] = count;
            }
            else
            {
                count = 0;
                count_nums[i] = 0;
            }
        }
        return min_len == n + 1 ? -1 : min_len;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {1};
    int k = 1;
    int result = solution.shortestSubarray(nums, k);
    cout << result << endl;
}