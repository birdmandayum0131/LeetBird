#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int smallestNumber(int n, int t)
    {
        for (int i = n;; i++)
        {
            int product = 1;
            int j = i;
            while (j > 0)
            {
                product *= j % 10;
                if (!product)
                    return i;
                j /= 10;
            }
            if (product % t == 0)
                return i;
        }
    }
};
int main(void)
{
    Solution solution;
    int n = 10, t = 2;
    long long output = solution.smallestNumber(n, t);
    cout << output << endl;
}