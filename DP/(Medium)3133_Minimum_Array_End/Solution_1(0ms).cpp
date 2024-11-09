#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    long long minEnd(int n, int x)
    {
        if (n == 1)
            return x;
        stack<int> zero_index;
        int max_zero_need = 1;
        long long possible_value = 1 << max_zero_need;
        while (n - 1 >= possible_value)
        {
            max_zero_need++;
            possible_value = 1 << max_zero_need;
        }
        // * find zero index
        int tmp = x;
        for (int i = 0, j = 0; j < max_zero_need; i++)
        {
            if (!(tmp & 1))
            {
                zero_index.push(i);
                j++;
            }
            tmp = tmp >> 1;
        }
        tmp = n - 1;
        int current_index = max_zero_need - 1;
        long long end_value = x;
        while (tmp)
        {
            int current_value = 1 << current_index;
            if (tmp >= current_value)
            {
                tmp -= current_value;
                end_value |= 1 << zero_index.top();
            }
            zero_index.pop();
            current_index--;
        }
        return end_value;
    }
};
int main(void)
{
    Solution solution;
    int n = 2, x = 7;
    long long output = solution.minEnd(n, x);
    cout << output << endl;
}