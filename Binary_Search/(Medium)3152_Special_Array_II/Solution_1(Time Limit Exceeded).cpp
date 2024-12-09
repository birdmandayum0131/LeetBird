#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        int m = queries.size();
        // * find every non-special pair
        vector<int> non_specials;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] % 2 == nums[i + 1] % 2)
                non_specials.push_back(i);

        vector<bool> results(m);
        for (int i = 0; i < m; i++)
        {
            bool is_special = true;
            // * check if query contain "any" non-special pair
            for (auto ns_pair : non_specials)
            {
                if (ns_pair >= queries[i][0] && ns_pair + 1 <= queries[i][1])
                {
                    is_special = false;
                    break;
                }
            }
            results[i] = is_special;
        }
        return results;
    }
};
// ! O(m * k) solution where k represent the number of non-special elements
int main(void)
{
    Solution solution;
    vector<int> nums = {4, 3, 1, 6};
    vector<vector<int>> queries = {{0, 2}, {2, 3}};
    vector<bool> is_specials = solution.isArraySpecial(nums, queries);
    for (auto is_special : is_specials)
        cout << is_special << endl;
}