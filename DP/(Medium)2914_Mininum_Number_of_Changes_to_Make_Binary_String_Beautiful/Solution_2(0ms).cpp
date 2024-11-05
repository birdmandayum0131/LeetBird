#include <iostream>

using namespace std;
class Solution
{
  public:
    int minChanges(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i += 2)
            if (s[i] != s[i + 1])
                count++;
        return count;
    }
};

int main(void)
{
    Solution solution;
    string s = "1001";
    int output = solution.minChanges(s);
    cout << output << endl;
}