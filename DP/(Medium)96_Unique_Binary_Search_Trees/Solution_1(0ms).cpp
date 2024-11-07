#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int numTrees(int n)
    {
        int *dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            count = 0;
            for (int j = 1; j <= i; j++)
                count += dp[j - 1] * dp[i - j];
            dp[i] = count;
        }
        return dp[n];
    }
};

int main(void)
{
    Solution solution;
    int n = 3;
    int output = solution.numTrees(n);
    cout << output << endl;
}