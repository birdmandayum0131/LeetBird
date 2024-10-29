#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> minimumPath = grid;
        for (int i = 0; i < minimumPath.size(); i++)
        {
            for (int j = 0; j < minimumPath[0].size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                    minimumPath[i][j] = minimumPath[i][j - 1] + grid[i][j];
                else if (j == 0)
                    minimumPath[i][j] = minimumPath[i - 1][j] + grid[i][j];
                else
                    minimumPath[i][j] = min(minimumPath[i - 1][j], minimumPath[i][j - 1]) + grid[i][j];
            }
        }
        return minimumPath[minimumPath.size() - 1][minimumPath[0].size() - 1];
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int output = solution.minPathSum(grid);
    cout << output << endl;
}