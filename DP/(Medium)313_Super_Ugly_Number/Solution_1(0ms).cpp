#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
    }
};
int main(void)
{
    Solution solution;
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};
    int output = solution.nthSuperUglyNumber(n, primes);
    cout << output << endl;
}