#include <chrono>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution
{
  public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s.substr(i, n - i) + s.substr(0, i) == goal)
                return true;
        }
        return false;
    }
};

int main(void)
{
    // auto start = chrono::steady_clock::now();
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    bool output = solution.rotateString(s, goal);
    cout << output << endl;
    // auto end = chrono::steady_clock::now();
    // cout << chrono::duration<double, std::nano>(end - start).count() << endl;
}