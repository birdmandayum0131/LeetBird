#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int *countArray = new int[26]();
        for (int i = 0; i < magazine.length(); i++)
            countArray[magazine[i] - 97]++;
        for (int i = 0; i < ransomNote.length(); i++)
        {
            if (countArray[ransomNote[i] - 97] == 0)
                return false;
            else
                countArray[ransomNote[i] - 97]--;
        }
        return true;
    }
};
int main(void)
{
    Solution solution;
    string ransomNote = "a";
    string magazine = "b";
    bool output = solution.canConstruct(ransomNote, magazine);
    cout << output << endl;
}