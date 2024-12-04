#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unsigned short charMap[256];
        int start = 0, max = 0;
        for (int i = 1; i <= s.length(); i++)
        {
            if (charMap[s[i - 1]] > start)
            {
                start = charMap[s[i - 1]];
                charMap[s[i - 1]] = i;
                continue;
            }
            charMap[s[i - 1]] = i;
            if (i - start > max)
            {
                max = i - start;
            }
        }
        return max;
    }
};
int main(void)
{
    Solution solution;
    string s = "abcbcbb";
    int length = solution.lengthOfLongestSubstring(s);
    cout << length << endl;
}