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
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> rotated_box(n, vector<char>(m, '.'));
        int stone_stack = 0;
        for (int i = 0; i < m; i++)
        {
            int rotated_col = m - i - 1;
            for (int j = 0; j < n; j++)
            {
                if (box[i][j] == '*') // * pop stack if is obstacle
                {
                    rotated_box[j][rotated_col] = '*';
                    for (int k = 1; k <= stone_stack; k++)
                        rotated_box[j - k][rotated_col] = '#';
                    stone_stack = 0;
                }
                else if (box[i][j] == '#')
                    stone_stack++;
            }
            for (int k = 1; k <= stone_stack; k++) // * pop stack if reach bottom
                rotated_box[n - k][rotated_col] = '#';
            stone_stack = 0;
        }
        return rotated_box;
    }
};

int main(void)
{
    Solution solution;
    vector<vector<char>> box = {{'#', '#', '*', '.', '*', '.'},
                                {'#', '#', '#', '*', '.', '.'},
                                {'#', '#', '#', '.', '#', '.'}};
    box = solution.rotateTheBox(box);
    for (auto row : box)
    {
        for (auto item : row)
            cout << item << " ";
        cout << "\b" << endl;
    }
}