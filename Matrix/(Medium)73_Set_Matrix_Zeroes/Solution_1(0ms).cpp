#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> zero_row(m);
        vector<bool> zero_col(m);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zero_row[i] = true;
                    zero_col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (zero_row[i] || zero_col[j])
                    matrix[i][j] = 0;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    solution.setZeroes(matrix);
    cout << "[";
    for (auto row : matrix)
    {
        cout << "[";
        for (auto col : row)
            cout << col << ", ";
        cout << "\b\b], ";
    }
    cout << "\b\b]" << endl;
}