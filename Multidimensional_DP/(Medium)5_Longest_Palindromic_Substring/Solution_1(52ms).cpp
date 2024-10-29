#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int maxIdx = 0, maxLen = 1;
        vector<int> longestPal(s.length() + s.length() - 1);
        for (int i = 0; i < longestPal.size(); i++)
        {
            if (i % 2 == 0)
                longestPal[i] = 1;
            else
                continue;
            for (int j = i - 1; j >= (i + 1) / 2; j--)
            {
                if ((longestPal[j] + 1) / 2 == (i - j) / 2 && s[(2 * j - i) / 2] == s[i / 2])
                {
                    longestPal[j] += 2;
                    if (longestPal[j] > maxLen)
                    {
                        maxLen = longestPal[j];
                        maxIdx = j;
                    }
                }
            }
        }
        for (int i = 0; i < longestPal.size(); i++)
            cout << longestPal[i] << ",";
        return s.substr((maxIdx + 1 - maxLen) / 2, maxLen);
    }
};
int main(void)
{
    Solution solution;
    string s = "aaaa";
    string output = solution.longestPalindrome(s);
    cout << output << endl;
}
