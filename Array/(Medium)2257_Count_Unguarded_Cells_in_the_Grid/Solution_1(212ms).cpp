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
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> combined_map(m, vector<int>(n, 0));
        for (auto guard : guards)
            combined_map[guard[0]][guard[1]] = 1;
        for (auto wall : walls)
            combined_map[wall[0]][wall[1]] = 2;

        vector<vector<tuple<bool, bool, bool, bool>>> grid_unguarded(
            m, vector<tuple<bool, bool, bool, bool>>(n, tuple<bool, bool, bool, bool>{}));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (combined_map[i][j] != 0)
                    get<0>(grid_unguarded[i][j]) = combined_map[i][j] == 1;
                else
                    get<0>(grid_unguarded[i][j]) =
                        (j == 0) ? false : get<0>(grid_unguarded[i][j - 1]);

                if (combined_map[i][n - 1 - j] != 0)
                    get<1>(grid_unguarded[i][n - 1 - j]) = combined_map[i][n - 1 - j] == 1;
                else
                    get<1>(grid_unguarded[i][n - 1 - j]) =
                        (j == 0) ? false : get<1>(grid_unguarded[i][n - j]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (combined_map[i][j] != 0)
                    get<2>(grid_unguarded[i][j]) = combined_map[i][j] == 1;
                else
                    get<2>(grid_unguarded[i][j]) =
                        (i == 0) ? false : get<2>(grid_unguarded[i - 1][j]);

                if (combined_map[m - 1 - i][j] != 0)
                    get<3>(grid_unguarded[m - 1 - i][j]) = combined_map[m - 1 - i][j] == 1;
                else
                    get<3>(grid_unguarded[m - 1 - i][j]) =
                        (i == 0) ? false : get<3>(grid_unguarded[m - i][j]);
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (combined_map[i][j] == 0)
                    if (!(get<0>(grid_unguarded[i][j]) || get<1>(grid_unguarded[i][j]) ||
                          get<2>(grid_unguarded[i][j]) || get<3>(grid_unguarded[i][j])))
                        count++;
        return count;
    }
};
//! time complexity O(m*n)
//? actually, O(m*n*4)
int main(void)
{
    Solution solution;
    int m = 4, n = 6;
    vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls = {{0, 1}, {2, 2}, {1, 4}};
    int result = solution.countUnguarded(m, n, guards, walls);
    cout << result << endl;
}