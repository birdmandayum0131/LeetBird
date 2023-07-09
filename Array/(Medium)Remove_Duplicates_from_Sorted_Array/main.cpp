#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int count = 1;
        int targetNum = nums[0];
        int expectedNums = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != targetNum)
            {
                count = 1;
            }
            else if (count > 2)
            {
                continue;
            }
            count++;
            nums[expectedNums] = nums[i];
            expectedNums++;
            targetNum = nums[i];
        }
        return expectedNums;
    }
};