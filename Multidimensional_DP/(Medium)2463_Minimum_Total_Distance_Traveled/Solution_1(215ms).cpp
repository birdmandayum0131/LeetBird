#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        quickSortRobot(robot);
        quickSortFactory(factory);
        // * minimumTotalDistance of frist j factory repair first i robots
        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(factory.size() + 1, 0));
        // * if no any factory, infinite step (will be filtered in minimum comparison)
        for (int i = 1; i <= robot.size(); i++)
            dp[i][0] = 2e11;
        for (int i = 0; i <= robot.size(); i++)
        {
            for (int j = 1; j <= factory.size(); j++)
            {
                long long minimum = 2e11;
                // * last factory repair last k robots, first j-1 factory repair first i-k robots
                for (int k = 0; k <= factory[j - 1][1] && k <= i; k++)
                {
                    if (dp[i - k][j - 1] == 2e11)
                        continue;
                    // * add minimum distance of first j-1 factory repair first i-k robots
                    long long distance = dp[i - k][j - 1];
                    // * sum last k robots distance to last factory
                    for (int l = i - 1; l >= i - k; l--)
                        distance += abs(robot[l] - factory[j - 1][0]);
                    if (distance < minimum)
                        minimum = distance;
                }
                dp[i][j] = minimum;
            }
        }
        return dp[robot.size()][factory.size()];
    }

  private:
    void quickSortRobot(vector<int> &robot)
    {
        std::vector<std::pair<int, int>> partions;
        partions.push_back({0, robot.size() - 1});
        while (int n = partions.size())
        {
            std::pair<int, int> part = partions[n - 1];
            partions.pop_back();
            int start = part.first;
            int end = part.second;
            int p = start;

            for (int i = p + 1; i <= end; i++)
                if (robot[i] < robot[start]) //* only compare first value of pair
                    swap(robot[++p], robot[i]);

            swap(robot[start], robot[p]);

            if (p - 1 > start)
                partions.push_back({start, p - 1});
            if (end > p + 1)
                partions.push_back({p + 1, end});
        }
    }
    void quickSortFactory(vector<vector<int>> &factory)
    {
        std::vector<std::pair<int, int>> partions;
        partions.push_back({0, factory.size() - 1});
        while (int n = partions.size())
        {
            std::pair<int, int> part = partions[n - 1];
            partions.pop_back();
            int start = part.first;
            int end = part.second;
            int p = start;

            for (int i = p + 1; i <= end; i++)
                if (factory[i][0] < factory[start][0]) //* only compare first value of pair
                    swap(factory[++p], factory[i]);

            swap(factory[start], factory[p]);

            if (p - 1 > start)
                partions.push_back({start, p - 1});
            if (end > p + 1)
                partions.push_back({p + 1, end});
        }
    }
};
int main(void)
{
    Solution solution;
    vector<int> robots = {0, 4, 6};
    vector<vector<int>> factory = {{2, 2}, {6, 2}};
    long long output = solution.minimumTotalDistance(robots, factory);
    cout << output << endl;
}