#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int direction = 0;
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        int total_len = (bottom + 1) * (right + 1);
        vector<int> output(total_len);
        int i = 0, j = 0, k = 0;
        while (!(i < top || i > bottom || j < left || j > right))
        {

            output[k] = matrix[i][j];
            k++;
            // check to switch direction
            if (direction == 0 && j == right)
            {
                direction = 1;
                top += 1;
            }
            else if (direction == 1 && i == bottom)
            {
                direction = 2;
                right -= 1;
            }
            else if (direction == 2 && j == left)
            {
                direction = 3;
                bottom -= 1;
            }
            else if (direction == 3 && i == top)
            {
                direction = 0;
                left += 1;
            }

            // step
            if (direction == 0)
                j += 1;
            else if (direction == 1)
                i += 1;
            else if (direction == 2)
                j -= 1;
            else
                i -= 1;
        }
        return output;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> output = solution.spiralOrder(matrix);
    for (int i = 0; i < output.size(); i++)
        cout << output[i] << ",";
    cout << "\b " << endl;
}