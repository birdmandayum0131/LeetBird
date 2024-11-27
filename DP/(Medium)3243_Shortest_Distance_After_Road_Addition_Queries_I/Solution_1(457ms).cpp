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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        // * shortest distance i to j
        vector<vector<int>> shortestDistance(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                shortestDistance[i][j] = j - i;

        int m = queries.size();
        vector<int> result(m);
        for (int i = 0; i < m; i++)
        {
            int begin = queries[i][0], end = queries[i][1];
            shortestDistance[begin][end] = 1;
            for (int j = 0; j <= begin; j++)
                for (int k = end; k < n; k++)
                    shortestDistance[j][k] =
                        min(shortestDistance[j][k],
                            shortestDistance[j][begin] + 1 + shortestDistance[end][k]);
            result[i] = shortestDistance[0][n - 1];
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    vector<int> paths = solution.shortestDistanceAfterQueries(n, queries);
    for (auto path : paths)
        cout << path << ", ";
    cout << "\b\b " << endl;
}