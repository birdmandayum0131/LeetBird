#include <chrono>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    int characterReplacement(string s, int k)
    {
        int n = s.length();
        array<int, 26> char_count{};
        // * sliding window
        int left = 0, right = 0; // [left, right)
        int left_iter = 0, right_iter = 0;
        int max_count = 0;
        int count;
        int max_char_count = 0;
        bool move_right = true;
        while (right < n)
        {
            if (move_right)
            {
                if (right_iter == n)
                    break;
                else
                {
                    //* peek right element, move right if can extend.
                    int peek_count = right - left + 1; // count+peek_element
                    char a = s[right_iter];
                    int peek_max_char_count = max(max_char_count, char_count[s[right_iter] - 'A'] + 1);
                    int peek_diff = peek_count - peek_max_char_count;
                    if (peek_diff <= k)
                    { // * can join this element
                        char_count[s[right_iter] - 'A']++;
                        right++;
                        right_iter++;
                        count = peek_count;
                        max_char_count = peek_max_char_count;
                        max_count = max(max_count, count);
                    }
                    else
                        move_right = false;
                }
            }
            else // * move left
            {
                // * left pointer don't need peek, just move until right_peek can move
                char_count[s[left_iter] - 'A']--;
                left++;
                // * recalculate max_char_count if char_count of left_iter equal to max_char_count
                if (char_count[s[left_iter] - 'A'] == max_char_count - 1)
                    max_char_count = *max_element(char_count.begin(), char_count.end());
                left_iter++;
                int peek_count = right - left + 1; // peek again to check if can move
                int peek_max_char_count = max(max_char_count, char_count[s[right_iter] - 'A'] + 1); // assume right_iter < n
                int peek_diff = peek_count - peek_max_char_count;
                if (peek_diff <= k)    // * can move to right
                    move_right = true; // * always trigger when left==right.
            }
        }
        return max_count;
    }
};

int main(void)
{
    Solution solution;
    string s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLH"
               "ADJADAGNNSBNCJQOF";
    int k = 4;
    int output = solution.characterReplacement(s, k);
    cout << output << endl;
}