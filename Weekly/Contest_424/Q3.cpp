#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        array<int, 100001> index{};
        long long count = 0;
        int queries_count = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += index[i];
            if (count >= nums[i])
                continue;
            else
            {
                while (j < n)
                {
                    if (i > queries[j][1])
                    {
                        j++;
                        queries_count++;
                        continue;
                    }
                    else if (i >= queries[j][0] && i <= queries[j][1])
                    {
                        index[i] += queries[j][2];
                        index[queries[j][1] + 1] -= queries[j][2];
                        count += queries[j][2];
                        queries_count++;
                        j++;
                        if (count >= nums[i])
                            break;
                    }
                    else
                    {
                        index[queries[j][0]] += queries[j][2];
                        index[queries[j][1] + 1] -= queries[j][2];
                        queries_count++;
                        j++;
                    }
                }
                if (count < nums[i])
                    return -1;
            }
        }
        return queries_count;
    }
};
// ! O(n+m)
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 1};
    vector<vector<int>> queries = {{0, 0, 1}, {1, 1, 5}, {0, 1, 5}, {1, 1, 1}, {0, 1, 3}, {0, 0, 4}, {1, 1, 2}, {0, 0, 1},
                                   {1, 1, 5}, {0, 1, 2}, {1, 1, 1}, {0, 1, 1}, {1, 1, 1}, {0, 1, 4}, {0, 0, 3}};
    int result = solution.minZeroArray(nums, queries);
    cout << result << endl;
}