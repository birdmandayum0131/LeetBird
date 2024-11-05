#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int numSquares(int n)
    {
        double sqrtn = sqrt(n);
        if (trunc(sqrtn) == sqrtn)
            return 1;
        int sqrt_n = int(sqrtn);
        int *dp = new int[n];
        for (int i = 0; i < sqrt_n; i++)
        {
            int square = (i + 1) * (i + 1);
            dp[square - 1] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            if (dp[i] == 1)
                continue;
            int min_square = INT16_MAX;
            for (int j = 0; j <= (i + 1) / 2 - 1; j++)
                if (dp[j] + dp[i - j - 1] < min_square)
                    min_square = dp[j] + dp[i - j - 1];
            dp[i] = min_square;
        }
        return dp[n - 1];
    }
};
int main(void)
{
    Solution solution;
    int n = 13;
    int output = solution.numSquares(n);
    cout << output << endl;
}