#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> maximumXOR(n);
        int xor_product = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xor_product ^= nums[i];
            maximumXOR[n - 1 - i] = (xor_product ^ ~0) & ~(~0 << maximumBit);
        }
        return maximumXOR;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums = {0, 1, 1, 3};
    int maximumBit = 2;
    vector<int> output = solution.getMaximumXor(nums, maximumBit);
    for (auto o : output)
        cout << o << ", ";
    cout << "\b\b " << endl;
}