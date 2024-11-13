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
        // * two pointer
        array<int, 26> char_count{};
        int n = s.length();
        if (n == 1)
            return 1;
        int left = 0, right = 0; // * [left, right)
        int max_count = 0;
        int count = 0;
        int diff_chars = 0;
        int most_char = 0;
        // * sliding window
        while (right < n)
        {
            // move right pointer
            count = right - left;
            while (right < n && diff_chars <= k)
            {
                char_count[s[right] - 'A']++;
                if (char_count[s[right] - 'A'] > most_char)
                    most_char = char_count[s[right] - 'A'];
                right++;
                count = right - left;
                diff_chars = count - most_char;
            }
            if (diff_chars > k){
                right--;
                char_count[s[right] - 'A']--;
                count = right - left;
                diff_chars = count - most_char;
            }
            max_count = max(max_count, count);
            if (right == n)
                return max_count;

            // move left pointer to next sliding window start
            while (diff_chars >= k && left < right)
            {
                char_count[s[left] - 'A']--;
                if (char_count[s[left] - 'A'] == most_char - 1)
                    most_char = *max_element(char_count.begin(), char_count.end());
                left++;
                count = right - left;
                diff_chars = count - most_char;
            }
        }
        return max_count; // * should not be triggered
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