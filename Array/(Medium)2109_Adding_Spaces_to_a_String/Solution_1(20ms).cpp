#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    string addSpaces(string s, vector<int> &spaces)
    {
        string result = "";
        int begin = 0;
        for (auto idx : spaces)
        {
            result += s.substr(begin, idx - begin) + " ";
            begin = idx;
        }
        if (begin != s.length())
            result += s.substr(begin, s.length() - begin);
        return result;
    }
};

int main(void)
{
    Solution solution;
    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = {8, 13, 15};
    string result = solution.addSpaces(s, spaces);
    cout << result << endl;
}