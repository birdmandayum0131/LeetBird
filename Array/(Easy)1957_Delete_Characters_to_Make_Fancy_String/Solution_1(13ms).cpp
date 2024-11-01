#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    string makeFancyString(string s)
    {
        string output = "";
        char currentCharacter = s[0];
        int count = 0;
        for (auto c : s)
        {
            if (c == currentCharacter)
            {
                if (count == 2)
                    continue;
                else
                {
                    count++;
                    output += c;
                }
            }
            else
            {
                currentCharacter = c;
                count = 1;
                output += c;
            }
        }
        return output;
    }
};
int main(void)
{
    Solution solution;
    string s = "leeetcode";
    string output = solution.makeFancyString(s);
    cout << output << endl;
}