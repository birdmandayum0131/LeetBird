#include <vector>
#include <tuple>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> word_map;
        for (int i = 0; i < wordDict.size(); i++)
            word_map[wordDict[i]] = true;

        bool *breakpoint = new bool[s.length() + 1]();
        breakpoint[0] = true;
        for (int i = 0; i < s.length(); i++)
        {
            // find breakpoint
            for (int j = i; j >= 0; j--)
            {
                if (breakpoint[j])
                {
                    if (word_map.find(s.substr(j, i - j + 1)) != word_map.end())
                    {
                        breakpoint[i + 1] = true;
                        break;
                    }
                }
            }
        }
        return breakpoint[s.length()];
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