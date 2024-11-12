#include <bitset>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int getSum(int a, int b)
    {
        int s = a ^ b;
        int c_out = a & b;
        int c_in = c_out << 1;
        while (c_in)
        {
            c_out = s & c_in;
            s = s ^ c_in;
            c_in = c_out << 1;
        }
        return s;
    }
};
int main(void)
{
    Solution solution;
    int a = 1992;
    cout << bitset<32>(20) << endl;
    int b = 2015;
    cout << bitset<32>(30) << endl;
    cout << bitset<32>(34) << endl;
    cout << bitset<32>(50) << endl;
    int value = solution.getSum(a, b);
    cout << value << endl;
}