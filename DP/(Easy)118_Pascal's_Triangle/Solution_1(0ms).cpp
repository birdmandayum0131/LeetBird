#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows, vector<int>(0));
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                    triangle[i].push_back(1);
                else
                    triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
        }
        return triangle;
    }
};

int main(void)
{
    Solution solution;
    int numRows = 5;
    vector<vector<int>> output = solution.generate(numRows);
    cout << "[";
    for (auto row : output)
    {
        cout << "[";
        for (auto col : row)
            cout << col << ", ";
        cout << "\b\b], ";
    }
    cout << "\b\b]" << endl;
}