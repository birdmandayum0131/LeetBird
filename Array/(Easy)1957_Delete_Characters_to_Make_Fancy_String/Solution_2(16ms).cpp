#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    string makeFancyString(string s)
    {
        char *outputarray = new char[s.length() + 1];
        char currentCharacter = s[0];
        int count = 0;
        int j = 0;
        for (auto c : s)
        {
            if (c == currentCharacter)
            {
                if (count == 2)
                    continue;
                else
                {
                    count++;
                    outputarray[j] = c;
                    j++;
                }
            }
            else
            {
                currentCharacter = c;
                count = 1;
                outputarray[j] = c;
                j++;
            }
        }
        outputarray[j] = '\0';
        return string(outputarray);
    }
};
int main(void)
{
    Solution solution;
    string s = "leeetcode";
    string output = solution.makeFancyString(s);
    cout << output << endl;
}