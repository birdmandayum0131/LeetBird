#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxSquareSize = 0;
        vector<vector<int>> maxSquare(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < maxSquare.size(); i++)
        {
            if (matrix[i][0] == '1')
            {
                maxSquare[i][0] = 1;
                maxSquareSize = 1;
            }
        }
        for (int j = 0; j < maxSquare[0].size(); j++)
        {
            if (matrix[0][j] == '1')
            {
                maxSquare[0][j] = 1;
                maxSquareSize = 1;
            }
        }
        for (int i = 1; i < maxSquare.size(); i++)
        {
            for (int j = 1; j < maxSquare[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    maxSquare[i][j] = min(min(maxSquare[i - 1][j - 1], maxSquare[i][j - 1]),
                                          maxSquare[i - 1][j]) +
                                      1;
                    if (maxSquare[i][j] > maxSquareSize)
                        maxSquareSize = maxSquare[i][j];
                }
            }
        }
        return maxSquareSize * maxSquareSize;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    int output = solution.maximalSquare(matrix);
    cout << output << endl;
}