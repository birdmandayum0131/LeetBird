#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result(2);
        map<int, int> pairIdx = {{target - numbers[0], 1}};
        for (int i = 1; i < numbers.size(); i++)
        {
            map<int, int>::iterator iter = pairIdx.find(numbers[i]);
            if (iter == pairIdx.end())
            {
                pairIdx[target - numbers[i]] = i + 1;
            }
            else
            {
                result[0] = pairIdx[numbers[i]];
                result[1] = i + 1;
                return result;
            }
        }
        return result;
    }
};
int main(void)
{
    Solution solution;
    int target = 9;
    vector<int> numbers{2, 7, 11, 15};
    vector<int> result = solution.twoSum(numbers, target);
    cout << result[0] << "," << result[1] << endl;
}