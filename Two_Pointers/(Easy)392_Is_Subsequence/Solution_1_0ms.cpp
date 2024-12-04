#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0;
        for (int j = 0; i < s.length() && j < t.length(); j++)
            if (t[j] == s[i])
                i++;

        if (i == s.length())
            return true;
        else
            return false;
    }
};
int main(void)
{
    Solution solution;
    string s = "abc";
    string t = "ahbgdc";
    bool result = solution.isSubsequence(s, t);
    cout << result << endl;
}