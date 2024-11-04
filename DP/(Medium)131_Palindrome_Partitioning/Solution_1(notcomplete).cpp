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
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> partions;
        findPalindrome(partions, s, 0);
    }

  private:
    void findPalindrome(vector<vector<string>> &partions, string s, int begin)
    {

        for (int i = 0; i < partions.size(); i++)
        {
            // if (partions[i].size() > 0)
        }
    }
};

// ! reduce unnecessary cost
int main(void)
{
    // auto start = chrono::steady_clock::now();
    Solution solution;
    string s = "aab";
    vector<vector<string>> output = solution.partition(s);
    cout << "[";
    for (int i = 0; i < output.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < output.size(); j++)
            cout << "\"" << output[i][j] << "\", " << endl;
        cout << "\b\b], ";
    }
    cout << "\b\b]" << endl;
    // auto end = chrono::steady_clock::now();
    // cout << chrono::duration<double, std::nano>(end - start).count() << endl;
}