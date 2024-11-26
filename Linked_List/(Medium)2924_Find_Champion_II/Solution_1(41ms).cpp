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
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<short> node_map(n);
        for (auto edge : edges)
            node_map[edge[1]] = edge[0] + 1;

        int champion = -1;
        int champion_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (node_map[i] == 0)
            {
                champion = i;
                champion_count++;
            }
        }
        if (champion_count == 1)
            return champion;
        else
            return -1;
    }
};

int main(void)
{
    Solution solution;
    int n = 4;
    vector<vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};
    int result = solution.findChampion(n, edges);
    cout << result << endl;
}