#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> anagrams;
        vector<vector<int>> letterMap;
        for (int i = 0; i < strs.size(); i++)
        {
            bool newWord = true;
            for (int j = 0; j < anagrams.size(); j++)
            {

                // compare len
                if (anagrams[j][0].length() == strs[i].length())
                {
                    vector<int> mapCopy = letterMap[j];

                    bool same = true;
                    for (int k = 0; k < strs[i].length(); k++)
                    {
                        char letter = strs[i][k] - 97;

                        if (same)
                        {
                            if (mapCopy[letter] == 0)
                                same = false;
                            else
                                mapCopy[letter]--;
                        }
                    }
                    if (same)
                    {
                        anagrams[j].push_back(strs[i]);

                        newWord = false;
                    }
                }
            }
            if (newWord)
            {
                vector<int> newMap(26, 0);
                for (int k = 0; k < strs[i].length(); k++)
                    newMap[strs[i][k] - 97]++;
                vector<string> newAnagrams = {strs[i]};
                anagrams.push_back(newAnagrams);
                letterMap.push_back(newMap);
            }
        }
        return anagrams;
    }
};
int main(void)
{
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> anagrams = solution.groupAnagrams(strs);
    for (int i = 0; i < anagrams.size(); i++)
    {
        for (int j = 0; j < anagrams[i].size(); j++)
        {
            cout << anagrams[i][j] << ", ";
        }
        cout << "\b\b \n"
             << endl;
    }
}