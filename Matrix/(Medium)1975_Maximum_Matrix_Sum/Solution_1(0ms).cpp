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
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int min_element = INT32_MAX, neg_count = 0;
        long long sum = 0;
        for (auto row : matrix)
        {
            for (auto item : row)
            {
                min_element = min(min_element, abs(item));
                if (item < 0)
                    neg_count++;
                sum += abs(item);
            }
        }
        if (min_element == 0 || neg_count % 2 == 0)
            return sum;
        else
            return sum - 2 * min_element;
    }
};

int main(void)
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    long long max_sum = solution.maxMatrixSum(matrix);
    cout << max_sum << endl;
}