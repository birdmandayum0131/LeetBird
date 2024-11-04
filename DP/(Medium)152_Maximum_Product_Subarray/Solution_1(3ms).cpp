#include <chrono>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        // find first non zero value start;
        int maxP = nums[0];
        int start = 0;
        while (start < nums.size() && nums[start] == 0)
            start++;
        if (start == nums.size())
            return 0;
        int currentProd = nums[start];
        int firstNegP = nums[start];
        int lastNegP = nums[start];
        int count = 1;
        for (int i = start + 1; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                maxP = max(maxP, 0);
                if (currentProd > 0)
                    maxP = max(maxP, currentProd);
                else
                {
                    if (count > 1)
                        maxP = max(maxP, currentProd / max(firstNegP, lastNegP));
                    else
                        maxP = max(maxP, currentProd);
                }
                start = i + 1;
                while (start < nums.size() && nums[start] == 0)
                    start++;
                if (start == nums.size())
                    return maxP;
                currentProd = nums[start];
                firstNegP = nums[start];
                lastNegP = nums[start];
                count = 1;
                i = start;
            }
            else
            {
                currentProd *= nums[i];
                if (firstNegP > 0)
                    firstNegP *= nums[i];
                if (nums[i] < 0)
                    lastNegP = nums[i];
                else
                    lastNegP *= nums[i];
                count++;
            }
        }
        if (start != nums.size())
        {
            if (currentProd > 0)
                maxP = max(maxP, currentProd);
            else
            {
                if (count > 1)
                    maxP = max(maxP, currentProd / max(firstNegP, lastNegP));
                else
                    maxP = max(maxP, currentProd);
            }
        }
        return maxP;
    }
};

int main(void)
{
    // auto start = chrono::steady_clock::now();
    Solution solution;
    vector<int> nums = {1, 0, -1, 2, 3, -5, -2};
    int output = solution.maxProduct(nums);
    cout << output << endl;
    // auto end = chrono::steady_clock::now();
    // cout << chrono::duration<double, std::nano>(end - start).count() << endl;
}