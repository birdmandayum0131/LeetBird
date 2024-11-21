#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
  public:
    int takeCharacters(string s, int k)
    {
        int n = s.length();
        array<int, 3> char_count{};
        int left = 0, right = n - 1;
        int min_count;
        // * init left
        while (left < n && !(char_count[0] >= k && char_count[1] >= k && char_count[2] >= k))
            char_count[s[left++] - 'a']++;
        left--;
        if (!(char_count[0] >= k && char_count[1] >= k && char_count[2] >= k))
            return -1;

        min_count = char_count[0] + char_count[1] + char_count[2];
        while (left >= 0)
        {
            if (char_count[s[left] - 'a'] > k)
            {
                char_count[s[left--] - 'a']--;
                min_count = min(min_count, char_count[0] + char_count[1] + char_count[2]);
            }
            else
                char_count[s[right--] - 'a']++;
        }
        return min_count;
    }
};
//! time complexity O(n) 
//? actually, O(2n)
int main(void)
{
    Solution solution;
    string s = "aabaaaacaabc";
    int k = 2;
    int result = solution.takeCharacters(s, k);
    cout << result << endl;
}