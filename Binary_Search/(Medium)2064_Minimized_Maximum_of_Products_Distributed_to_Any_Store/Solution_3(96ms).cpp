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
        // ! So, that is the time limit keypoint, binary search can speed up with this.
        int max_element = quantities[0];
        int left = start_num;
        int right = max_element;
        while (left < right)
        {
            int max_products = (left + right) / 2; // ! binary search
            // * calculate the minimum given store amount
            int given_store_amount = 0;
            for (auto quantity : quantities)
            {
                given_store_amount += ceil(quantity / float(max_products));
                // * stopped if the least possible given store less than(fill the remaining with zero) or equal to n.
                if (given_store_amount > n) // * sort quantity can speed up the breakpoint.
                    break;
            }
            if (given_store_amount <= n) // * can be distributed
                right = max_products;
            else
                left = max_products + 1;
        }
        return left;
    }
};
int main(void)
{
    Solution solution;
    int n = 6;
    vector<int> quantities = {11, 6};
    int output = solution.minimizedMaximum(n, quantities);
    cout << output << endl;
}