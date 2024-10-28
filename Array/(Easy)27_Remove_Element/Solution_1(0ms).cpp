#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int tmp;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            if (nums[start] == val)
            {
                tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
                end--;
            }
            else
            {
                start++;
            }
        }
        return end + 1;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int k = solution.removeElement(nums, 2);
    cout << k << endl;
    for (int i = 0; i < k; i++)
        cout << nums[i] << ", ";
    cout << "\b " << endl;
}