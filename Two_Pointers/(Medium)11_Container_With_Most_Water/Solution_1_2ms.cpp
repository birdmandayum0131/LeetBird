#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        for (int i = 0, j = height.size() - 1; i != j;)
        {
            // Compare max and current
            int width = j - i;
            if (height[i] < height[j])
            {
                int area = height[i] * width;
                if (max < area)
                    max = area;
                i++;
            }
            else
            {
                int area = height[j] * width;
                if (max < area)
                    max = area;
                j--;
            }
        }
        return max;
    }
};
int main(void)
{
    Solution solution;
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = solution.maxArea(height);
    cout << result << endl;
}