#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool canMakeSubsequence(string str1, string str2)
    {
        // * two pointer solution
        int ptr1 = 0, ptr2 = 0;
        int n = str1.length(), m = str2.length();
        while (ptr1 != n)
        {
            if (ptr2 == m)
                break;

            // * compare possible transition of two pointed character
            int diff = (str2[ptr2] - str1[ptr1] + 26) % 26;
            if (diff <= 1)
                ptr2++;
            ptr1++;
        }
        if (ptr2 == m)
            return true;
        else
            return false;
    }
};

int main(void)
{
    Solution solution;
    string s1 = "zc";
    string s2 = "ad";
    bool result = solution.canMakeSubsequence(s1, s2);
    string output = result ? "true" : "false";
    cout << output << endl;
}