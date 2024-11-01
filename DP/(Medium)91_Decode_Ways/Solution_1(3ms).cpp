#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;

        if (s.length() == 1)
            return 1;

        int *dp = new int[s.length()];
        dp[0] = 1;
        if (s[0] == '1')
        {
            if (s[1] == '0')
                dp[1] = 1;
            else
                dp[1] = 2;
        }
        else if (s[0] == '2')
        {
            if (s[1] == '0' || s[1] == '7' || s[1] == '8' || s[1] == '9')
                dp[1] = 1;
            else
                dp[1] = 2;
        }
        else
        {
            if (s[1] == '0')
                dp[1] = 0;
            else
                dp[1] = 1;
        }

        for (int i = 2; i < s.length(); i++)
        {
            int count = 0;
            if (s[i - 1] == '1')
            {
                if (s[i] == '0')
                    count = dp[i - 2];
                else
                    count = dp[i - 1] + dp[i - 2];
            }
            else if (s[i - 1] == '2')
            {
                if (s[i] == '0')
                    count = dp[i - 2];
                else if (s[i] == '7' || s[i] == '8' || s[i] == '9')
                    count = dp[i - 1];
                else
                    count = dp[i - 1] + dp[i - 2];
            }
            else
            {
                if (s[i] == '0')
                    return 0;
                else
                    count = dp[i - 1];
            }
            dp[i] = count;
        }
        return dp[s.length() - 1];
    }
};

int main(void)
{
    Solution solution;
    string s = "226";
    int output = solution.numDecodings(s);
    cout << output << endl;
}