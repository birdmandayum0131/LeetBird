#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        if (s.length() == 0)
            return true;
        bool canBreak = false;
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (wordDict[i][0] == s[0] && s.substr(0, wordDict[i].length()) == wordDict[i])
                canBreak = canBreak || wordBreak(s.substr(wordDict[i].length(), s.length() - wordDict[i].length()), wordDict);
        }
        return canBreak;
    }
};
int main(void)
{
    Solution solution;
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa", "aa"};
    bool output = solution.wordBreak(s, wordDict);
    cout << output << endl;
}