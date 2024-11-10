#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int n = nums.size();
        int *num_select = new int[100001]();
        int max_num = 0;
        int min_num = 100000;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > max_num)
                max_num = nums[i];
            if (nums[i] < min_num)
                min_num = nums[i];
            num_select[nums[i]]++;
        }
        int max = 1;
        int count = 0;
        for (int i = min_num; i <= max_num; i++)
        {
            count = 0;
            for (int j = -k; j <= k; j++)
                if (i + j > 0 && i + j <= 100000)
                    count += num_select[i + j];
            if (count > num_select[i] + numOperations)
                count = num_select[i] + numOperations;
            if (count > max)
            {
                max = count;
            }
        }
        return max;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {5, 11, 20, 20};
    int k = 5;
    int numOperations = 1;
    int output = solution.maxFrequency(nums, k, numOperations);
    cout << output << endl;
}