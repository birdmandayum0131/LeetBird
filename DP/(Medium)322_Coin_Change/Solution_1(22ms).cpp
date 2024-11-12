#include <algorithm>
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++)
        {
            int count = i + 1;
            for (auto coin : coins)
            {
                if (coin > i)
                    break;
                else if (dp[i - coin] < 0)
                    continue;
                else
                    count = min(count, dp[i - coin] + 1);
            }
            dp[i] = count > i ? -1 : count;
        }
        return dp[amount];
    }
};
int main(void)
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int output = solution.coinChange(coins, amount);
    cout << output << endl;
}