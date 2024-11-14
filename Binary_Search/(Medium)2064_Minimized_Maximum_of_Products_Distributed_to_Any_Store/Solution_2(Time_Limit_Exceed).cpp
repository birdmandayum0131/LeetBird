#include <cmath>
#include <iostream>
#include <numeric>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        // * start from ceil(sum(quantities) / n), cuz every number < floor(sum(quantities) / n) can't be the max amount.
        // ! might be overflow on reduce, cuz maximum sum is 10^5 * 10^5
        int start_num = ceil(reduce(quantities.begin(), quantities.end(), 0LL) / float(n));
        sort(quantities.begin(), quantities.end(), greater<int>());
        // ? Actually, max possible of start_num is max_element(quantities), but I don't want to waste time on it.
        for (int max_products = start_num;;)
        {
            int min_remainder_quotient_ratio = INT_MAX;
            // * calculate the minimum given store amount
            int given_store_amount = 0;
            for (auto quantity : quantities)
            {
                int quotient = quantity / max_products;
                int remainder = quantity % max_products;
                if (remainder == 0)
                    given_store_amount += quotient;
                else
                {
                    given_store_amount += quotient + 1;
                    if (quotient != 0)
                        min_remainder_quotient_ratio =
                            min(min_remainder_quotient_ratio, int(ceil(remainder / float(quotient))));
                }
                // * stopped if the least possible given store less than(fill the remaining with zero) or equal to n.
                if (given_store_amount > n) // * sort quantity can speed up the breakpoint.
                    break;
            }
            if (given_store_amount <= n)
                return max_products;
            else
                max_products += min_remainder_quotient_ratio;
        }
        return n; // * should not be triggered
    }
};
int main(void)
{
    Solution solution;
    int n = 2;
    vector<int> quantities = {5, 7};
    int output = solution.minimizedMaximum(n, quantities);
    cout << output << endl;
}