#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<bool>> interleavemap(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        for (int i = s1.length(); i >= 0; i--)
        {
            for (int j = s2.length(); j >= 0; j--)
            {
                if (i == s1.length() && j == s2.length())
                    interleavemap[i][j] = true; // "" and "" can form ""
                else if (i == s1.length())
                {
                    if (s2[j] == s3[i + j])
                        interleavemap[i][j] = interleavemap[i][j + 1];
                }
                else if (j == s2.length())
                {
                    if (s1[i] == s3[i + j])
                        interleavemap[i][j] = interleavemap[i + 1][j];
                }
                else
                {
                    if (s1[i] == s3[i + j] && s2[j] == s3[i + j])
                        interleavemap[i][j] = interleavemap[i + 1][j] || interleavemap[i][j + 1];
                    else if (s1[i] == s3[i + j])
                        interleavemap[i][j] = interleavemap[i + 1][j];
                    else if (s2[j] == s3[i + j])
                        interleavemap[i][j] = interleavemap[i][j + 1];
                }
            }
        }
        return interleavemap[0][0];

        // if (s1[0] == s3[0] && s2[0] == s3[0])
        // {
        //     return isInterleave(s1.substr(1, s1.length() - 1), s2, s3.substr(1, s3.length() - 1))
        //     ||
        //            isInterleave(s1, s2.substr(1, s2.length() - 1), s3.substr(1, s3.length() -
        //            1));
        // }
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