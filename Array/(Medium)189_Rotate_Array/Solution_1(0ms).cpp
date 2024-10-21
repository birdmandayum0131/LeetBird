#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> clone = nums;
        for (int i = 0; i < nums.size(); i++)
            nums[(i + k) % nums.size()] = clone[i];
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    solution.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ",";
    cout << "\b " << endl;
}