#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int profits;
        int count = 0;
        int minIdx = 0;
        int min = gas[0] - cost[0];
        for (int i = 0; i < gas.size(); i++)
        {
            profits = gas[i] - cost[i];
            count += profits;
            if (count < min)
            {
                min = count;
                minIdx = i;
            }
        }
        if (count < 0)
            return -1;
        else
            return (minIdx + 1) % gas.size();
    }
};
int main(void)
{
    Solution solution;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int ith = solution.canCompleteCircuit(gas, cost);
    cout << ith << endl;
}