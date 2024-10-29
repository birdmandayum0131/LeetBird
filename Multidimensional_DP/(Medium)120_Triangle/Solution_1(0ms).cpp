#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        int minimum;
        vector<vector<int>> minimumCheckpoint = triangle;
        for (int row = 1; row < triangle.size(); row++)
        {
            for (int col = 0; col < triangle[row].size(); col++)
            {
                if (col == 0)
                    minimumCheckpoint[row][col] = minimumCheckpoint[row - 1][col] + triangle[row][col];
                else if (col == triangle[row].size() - 1)
                    minimumCheckpoint[row][col] = minimumCheckpoint[row - 1][col - 1] + triangle[row][col];
                else
                    minimumCheckpoint[row][col] = min(minimumCheckpoint[row - 1][col - 1], minimumCheckpoint[row - 1][col]) + triangle[row][col];
                if (row == triangle.size() - 1)
                    if (col == 0)
                        minimum = minimumCheckpoint[row][col];
                    else
                        minimum = min(minimumCheckpoint[row][col], minimum);
            }
        }
        return minimum;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int output = solution.minimumTotal(triangle);
    cout << output << endl;
}