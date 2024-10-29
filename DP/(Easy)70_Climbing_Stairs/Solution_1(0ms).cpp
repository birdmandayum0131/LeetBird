#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;

        int *ways = new int[n];
        ways[0] = 1;
        ways[1] = 2;
        for (int i = 2; i < n; i++)
        {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n - 1];
    }
};
int main(void)
{
    Solution solution;
    int n = 3;
    int output = solution.climbStairs(n);
    cout << output << endl;
}