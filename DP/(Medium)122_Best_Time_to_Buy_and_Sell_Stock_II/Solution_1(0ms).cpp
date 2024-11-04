#include <chrono>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int *dp = new int[n]();
        for (int i = 1; i < n; i++)
        {
            if (prices[i] >= prices[i - 1])
                dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            else
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }
};

// ! reduce unnecessary cost
int main(void)
{
    // auto start = chrono::steady_clock::now();
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int output = solution.maxProfit(prices);
    cout << output << endl;
    // auto end = chrono::steady_clock::now();
    // cout << chrono::duration<double, std::nano>(end - start).count() << endl;
}