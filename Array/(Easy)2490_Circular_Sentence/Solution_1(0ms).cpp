#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool isCircularSentence(string sentence)
    {
        char firstword = sentence[0];
        if (firstword != sentence[sentence.length() - 1])
            return false;
        for (int i = 0; i < sentence.length(); i++)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        return true;
    }
};

int main(void)
{
    Solution solution;
    string sentence = "leetcode exercises sound delightful";
    bool output = solution.isCircularSentence(sentence);
    cout << output << endl;
}