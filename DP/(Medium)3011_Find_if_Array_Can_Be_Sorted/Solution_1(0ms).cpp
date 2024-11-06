#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool canSortArray(vector<int> &nums)
    {
        int current_bit = get_set_bits(nums[0]);
        int last_max = 0;
        int local_max = nums[0];
        int local_min = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int bits = get_set_bits(nums[i]);
            if (bits == current_bit)
            {
                local_max = max(local_max, nums[i]);
                local_min = min(local_min, nums[i]);
            }
            else
            {
                if (local_min < last_max)
                    return false;
                last_max = local_max;
                current_bit = bits;
                local_max = nums[i];
                local_min = nums[i];
            }
        }
        if (local_min < last_max)
            return false;
        return true;
    }

  private:
    int get_set_bits(int n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
                count++;
            n >>= 1;
        }
        return count;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {3, 16, 8, 4, 2};
    bool output = solution.canSortArray(nums);
    cout << output << endl;
}