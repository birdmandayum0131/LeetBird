#include <chrono>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    string compressedString(string word)
    {
        string comp = "";
        char prefix = word[0];
        int count = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (count == 9)
            {
                comp.push_back('9');
                comp.push_back(prefix);
                count = 0;
            }
            if (word[i] == prefix)
                count++;
            else
            {
                if (count > 0)
                {
                    comp.push_back('0' + count);
                    comp.push_back(prefix);
                }
                prefix = word[i];
                count = 1;
            }
        }
        comp.push_back('0' + count);
        comp.push_back(prefix);
        return comp;
    }
};

// ! push_back a char is faster than type conversion
int main(void)
{
    // auto start = chrono::steady_clock::now();
    Solution solution;
    string word = "aaaaaaaaay";
    string output = solution.compressedString(word);
    cout << output << endl;
    // auto end = chrono::steady_clock::now();
    // cout << chrono::duration<double, std::nano>(end - start).count() << endl;
}