#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row;
        for (int i = 0; i < rowIndex + 1; i++)
            row.push_back(getValue(rowIndex, i));
        return row;
    }

  private:
    int getValue(int row, int col)
    {
        if (col == 0 || col == row)
            return 1;
        else
            return getValue(row - 1, col - 1) + getValue(row - 1, col);
    }
};

int main(void)
{
    Solution solution;
    int rowIndex = 30;
    vector<int> output = solution.getRow(rowIndex);
    cout << "[";
    for (auto col : output)
        cout << col << ", ";
    cout << "\b\b]" << endl;
}