#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count = 0;
            for (auto query : queries)
                if (i >= query[0] && i <= query[1])
                    count++;
            if (count < nums[i])
                return false;
        }
        return true;
    }
};
// ! O(n*m) time complexity.
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 1};
    vector<vector<int>> queries = {{0, 0, 1}, {1, 1, 5}, {0, 1, 5}, {1, 1, 1}, {0, 1, 3}, {0, 0, 4}, {1, 1, 2}, {0, 0, 1},
                                   {1, 1, 5}, {0, 1, 2}, {1, 1, 1}, {0, 1, 1}, {1, 1, 1}, {0, 1, 4}, {0, 0, 3}};
    bool result = solution.isZeroArray(nums, queries);
    cout << result << endl;
}