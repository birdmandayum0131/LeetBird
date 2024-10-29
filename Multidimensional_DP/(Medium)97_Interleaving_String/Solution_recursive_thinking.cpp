#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() == 0 && s2.length() == 0 && s3.length() == 0)
            return true;
        else if ((s1.length() == 0 && s2.length() == 0) || s3.length() == 0)
            return false;
        if (s1[0] == s3[0] && s2[0] == s3[0])
        {
            return isInterleave(s1.substr(1, s1.length() - 1), s2, s3.substr(1, s3.length() - 1)) ||
                   isInterleave(s1, s2.substr(1, s2.length() - 1), s3.substr(1, s3.length() - 1));
        }
        else if (s1[0] == s3[0])
        {
            return isInterleave(s1.substr(1, s1.length() - 1), s2, s3.substr(1, s3.length() - 1));
        }
        else if (s2[0] == s3[0])
        {
            return isInterleave(s1, s2.substr(1, s2.length() - 1), s3.substr(1, s3.length() - 1));
        }
        else
        {
            return false;
        }
    }
};
int main(void)
{
    Solution solution;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool output = solution.isInterleave(s1, s2, s3);
    cout << output << endl;
}