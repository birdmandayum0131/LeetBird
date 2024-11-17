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
        array<int, 100001> index{};
        for (auto query : queries)
        {
            index[query[0]]++;
            index[query[1] + 1]--;
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += index[i];
            if (count < nums[i])
                return false;
        }
        return true;
    }
};
// ! O(n+m)
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 1};
    vector<vector<int>> queries = {{0, 0, 1}, {1, 1, 5}, {0, 1, 5}, {1, 1, 1}, {0, 1, 3}, {0, 0, 4}, {1, 1, 2}, {0, 0, 1},
                                   {1, 1, 5}, {0, 1, 2}, {1, 1, 1}, {0, 1, 1}, {1, 1, 1}, {0, 1, 4}, {0, 0, 3}};
    bool result = solution.isZeroArray(nums, queries);
    cout << result << endl;
}