#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class CustomListNode
{
  public:
    int val;
    array<CustomListNode *, 2> next{};
    int count = 0;
    CustomListNode() : val(0) {};
    CustomListNode(int n) : val(n) {};
};

class Solution
{
  public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        CustomListNode *root = new CustomListNode(0);
        int max_row_count = 0;
        for (int i = 0; i < rows; i++)
        {
            int bias = matrix[i][0] == 0 ? 0 : 1;
            CustomListNode *iter = root;
            for (int j = 1; j < cols; j++)
            {
                int val = (matrix[i][j] + bias) % 2;
                if (iter->next[val] == nullptr)
                    iter->next[val] = new CustomListNode(val);
                iter = iter->next[val];
            }
            max_row_count = max(max_row_count, ++(iter->count));
        }
        return max_row_count;
    }
};

int main(void)
{
    Solution solution;
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};
    int result = solution.maxEqualRowsAfterFlips(matrix);
    cout << result << endl;
}