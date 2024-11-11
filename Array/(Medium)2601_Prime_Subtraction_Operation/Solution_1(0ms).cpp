#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    bool primeSubOperation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> primes = {2};
        int max_value = *max_element(nums.begin(), nums.end());
        // * fill primes
        for (int i = 3; i < max_value; i++)
        {
            bool is_prime = true;
            for (int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++)
            {
                if (i % primes[j] == 0)
                {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime)
                primes.push_back(i);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] >= nums[i + 1])
            {
                // * find smallest prime greater than nums[i] - nums[i+1] and lower than nums[i]
                int target_prime = 0;
                for (int j = 0; j < primes.size() && primes[j] < nums[i]; j++)
                {
                    if (primes[j] > nums[i] - nums[i + 1])
                    {
                        target_prime = primes[j];
                        break;
                    }
                }
                if (target_prime)
                    nums[i] -= target_prime;
                else
                    return false;
            }
        }
        return true;
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums = {5, 8, 3};
    bool output = solution.primeSubOperation(nums);
    cout << output << endl;
}