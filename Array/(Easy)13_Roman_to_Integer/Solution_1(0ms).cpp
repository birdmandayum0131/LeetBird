#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        int value = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'I')
            {
                value += 1;
            }
            else if (s[i] == 'V')
            {

                if (i > 0 && s[i - 1] == 'I')
                {
                    value += 3;
                }
                else
                {
                    value += 5;
                }
            }
            else if (s[i] == 'X')
            {
                if (i > 0 && s[i - 1] == 'I')
                {
                    value += 8;
                }
                else
                {
                    value += 10;
                }
            }
            else if (s[i] == 'L')
            {
                if (i > 0 && s[i - 1] == 'X')
                {
                    value += 30;
                }
                else
                {
                    value += 50;
                }
            }
            else if (s[i] == 'C')
            {
                if (i > 0 && s[i - 1] == 'X')
                {
                    value += 80;
                }
                else
                {
                    value += 100;
                }
            }
            else if (s[i] == 'D')
            {
                if (i > 0 && s[i - 1] == 'C')
                {
                    value += 300;
                }
                else
                {
                    value += 500;
                }
            }
            else if (s[i] == 'M')
            {
                if (i > 0 && s[i - 1] == 'C')
                {
                    value += 800;
                }
                else
                {
                    value += 1000;
                }
            }
        }
        return value;
    }
};
int main(void)
{
    Solution solution;
    string s = "MCMXCIV";
    int value = solution.romanToInt(s);
    cout << value << endl;
}