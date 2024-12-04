#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int start = 0, max = 1;
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = i - 1; j >= start; j--)
            {
                if (s[i] == s[j])
                {
                    start = j + 1;
                    continue;
                }
            }
            if (i - start + 1 > max)
            {
                max = i - start + 1;
            }
        }
        return max;
    }
};
int main(void)
{
    Solution solution;
    string s = "abcabcbb";
    int length = solution.lengthOfLongestSubstring(s);
    cout << length << endl;
}