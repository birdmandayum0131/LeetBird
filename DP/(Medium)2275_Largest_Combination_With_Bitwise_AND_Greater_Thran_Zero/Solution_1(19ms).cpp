#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
  public:
    int largestCombination(vector<int> &candidates)
    {
        // * 2^24 = 16,777,216 > 10^7
        int *bit_count = new int[25]();
        int i = 0;
        for (auto candidate : candidates)
        {
            i = 0;
            while (candidate != 0)
            {
                if (candidate & 1)
                    bit_count[i]++;
                candidate >>= 1;
                i++;
            }
        }
        int max_count = 0;
        for (int i = 0; i < 25; i++)
            if (bit_count[i] > max_count)
                max_count = bit_count[i];
        return max_count;
    }
};
int main(void)
{
    Solution solution;
    vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};
    int output = solution.largestCombination(candidates);
    cout << output << endl;
}