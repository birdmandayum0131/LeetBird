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
        int *dp = new int[n + 1];
        int *square = new int[sqrt_n + 1];
        for (int i = 1; i <= sqrt_n; i++)
        {
            int square_i = i * i;
            square[i] = square_i;
            dp[square_i] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == 1)
                continue;
            int min_square = INT16_MAX;
            for (int j = 1; j <= sqrt(i); j++)
                if (1 + dp[i - square[j]] < min_square)
                    min_square = 1 + dp[i - square[j]];
            dp[i] = min_square;
        }
        return dp[n];
    }
};
int main(void)
{
    Solution solution;
    int n = 13;
    int output = solution.numSquares(n);
    cout << output << endl;
}