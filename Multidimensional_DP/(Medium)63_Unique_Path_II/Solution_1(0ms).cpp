#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> ways = obstacleGrid;
        for (int i = 0; i < ways.size(); i++)
        {
            for (int j = 0; j < ways[0].size(); j++)
            {
                if (obstacleGrid[i][j] > 0)
                    ways[i][j] = 0;
                else if (i == 0 && j == 0)
                    ways[i][j] = 1;
                else if (i == 0)
                    ways[i][j] = ways[i][j - 1];
                else if (j == 0)
                    ways[i][j] = ways[i - 1][j];
                else
                    ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
            }
        }
        return ways[ways.size() - 1][ways[0].size() - 1];
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int output = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << output << endl;
}