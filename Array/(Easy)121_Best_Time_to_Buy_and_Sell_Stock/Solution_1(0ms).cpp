#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int minimum = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] <= minimum)
                minimum = prices[i];
            else
                max_profit = max(max_profit, prices[i] - minimum);
        }
        return max_profit;
    }
};

int main(void)
{
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int output = solution.maxProfit(prices);
    cout << output << endl;
}