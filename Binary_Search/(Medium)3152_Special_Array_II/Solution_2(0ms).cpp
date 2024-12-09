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
        // * always special if nums length is 1
        if (nums.size() == 1)
            return vector<bool>(queries.size(), true);

        int n = nums.size();
        int m = queries.size();
        // * find every non-special pair
        vector<int> non_specials;
        for (int i = 0; i < n - 1; i++)
            if (nums[i] % 2 == nums[i + 1] % 2)
                non_specials.push_back(i);

        // * always special if there is no non_specials pair
        if (non_specials.size() == 0)
            return vector<bool>(queries.size(), true);

        vector<bool> results(m);
        for (int i = 0; i < m; i++)
        {
            bool is_special = true;
            // * check if query contain "any" non-special pair
            // ? speed up with binary search
            int left = 0, right = non_specials.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (non_specials[mid] >= queries[i][0] && non_specials[mid] + 1 <= queries[i][1])
                {
                    is_special = false;
                    break;
                }
                if (non_specials[mid] < queries[i][0])
                    left = mid + 1;
                else
                    right = mid;
            }
            if (non_specials[left] >= queries[i][0] && non_specials[left] + 1 <= queries[i][1])
                is_special = false;

            results[i] = is_special;
        }
        return results;
    }
};
// ! O(m * log2(k)) solution where k represent the number of non-special elements
int main(void)
{
    Solution solution;
    vector<int> nums = {1, 4};
    vector<vector<int>> queries = {{0, 1}};
    vector<bool> is_specials = solution.isArraySpecial(nums, queries);
    for (auto is_special : is_specials)
        cout << is_special << endl;
}