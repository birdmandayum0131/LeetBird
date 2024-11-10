#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());

        int *num_count = new int[100002]();
        map<int, int> checkpoints;
        for (auto num : nums)
        {
            num_count[num]++;
            checkpoints[max(num - k, 1)]++;
            checkpoints[num] += 0;
            checkpoints[min(num + k + 1, 100001)]--;
        }

        int element_count = 0;
        int one_move_to_element;
        int max_freq = 1;
        for (auto checkpoint : checkpoints)
        {
            element_count += checkpoint.second;
            one_move_to_element = element_count - num_count[checkpoint.first];
            // * zero move to element + one move to element
            if (num_count[checkpoint.first] + min(one_move_to_element, numOperations) > max_freq)
                max_freq = num_count[checkpoint.first] + min(one_move_to_element, numOperations);
        }
        return max_freq;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {100000, 100000};
    int k = 1;
    int numOperations = 1;
    int output = solution.maxFrequency(nums, k, numOperations);
    cout << output << endl;
}