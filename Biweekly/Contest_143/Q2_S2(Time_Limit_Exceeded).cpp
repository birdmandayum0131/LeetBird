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
        vector<vector<int>> num_select(100001, vector<int>(2, 0));
        int max = 1;
        int max_num = 0;
        int min_num = 100000;
        for (int i = 0; i < n; i++)
        {
            num_select[nums[i]][0]++;
            if (nums[i] > max_num)
                max_num = nums[i];
            if (nums[i] < min_num)
                min_num = nums[i];
            for (int j = -k; j <= k; j++)
                if (j != 0 && nums[i] + j > 0 && nums[i] + j <= 100000)
                    num_select[nums[i] + j][1]++;
        }

        for (int i = min_num; i <= max_num; i++)
        {
            int count = min(numOperations, num_select[i][1]);
            if (num_select[i][0] + count > max)
                max = num_select[i][0] + count;
        }
        return max;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {143, 116, 129, 92, 112};
    int k = 53;
    int numOperations = 4;
    int output = solution.maxFrequency(nums, k, numOperations);
    cout << output << endl;
}