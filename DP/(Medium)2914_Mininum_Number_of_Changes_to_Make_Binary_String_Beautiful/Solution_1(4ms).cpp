#include <iostream>

using namespace std;
class Solution
{
  public:
    int minChanges(string s)
    {
        int n = s.length();
        int *dp = new int[n];
        dp[1] = abs(s[1] - s[0]);
        for (int i = 3; i < n; i += 2)
            dp[i] = (dp[i] == dp[i - 1] ? 0 : 1) + dp[i - 2];
        return dp[n - 1];
    }
};

int main(void)
{
    Solution solution;
    string s = "1001";
    int output = solution.minChanges(s);
    cout << output << endl;
}