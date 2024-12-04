#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result(2);
        int start = 0;
        int end = numbers.size() - 1;
        int sum = numbers[start] + numbers[end];

        while (sum != target)
        {
            if (sum < target)
                start++;
            else
                end--;
            sum = numbers[start] + numbers[end];
        }
        result[0] = start + 1;
        result[1] = end + 1;
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