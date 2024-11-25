#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        unordered_map<string, int> min_step_map;
        string target = "123450";
        min_step_map[target] = INT32_MAX;
        pair<int, int> zero_index;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == 0)
                    zero_index = {i, j};
        solvePuzzle(min_step_map, board, target, 0, zero_index);
        if (min_step_map[target] == INT32_MAX)
            return -1;
        else
            return min_step_map[target];
    }

  private:
    void solvePuzzle(unordered_map<string, int> &min_step_map, vector<vector<int>> board,
                     string target, int step, pair<int, int> zero_index)
    {
        string current_state = board2string(board);
        if (min_step_map.find(current_state) != min_step_map.end() &&
            min_step_map[current_state] <= step)
            return;
        if (step >= min_step_map[target])
            return;
        min_step_map[current_state] = step;
        int target_row = zero_index.first == 0 ? 1 : 0;
        swap(board[zero_index.first][zero_index.second],
             board[target_row][zero_index.second]);
        solvePuzzle(min_step_map, board, target, step + 1, {target_row, zero_index.second});
        swap(board[zero_index.first][zero_index.second],
             board[target_row][zero_index.second]);

        if (zero_index.second > 0)
        {
            swap(board[zero_index.first][zero_index.second],
                 board[zero_index.first][zero_index.second - 1]);
            solvePuzzle(min_step_map, board, target, step + 1,
                        {zero_index.first, zero_index.second - 1});
            swap(board[zero_index.first][zero_index.second],
                 board[zero_index.first][zero_index.second - 1]);
        }
        if (zero_index.second < board[0].size() - 1)
        {
            swap(board[zero_index.first][zero_index.second],
                 board[zero_index.first][zero_index.second + 1]);
            solvePuzzle(min_step_map, board, target, step + 1,
                        {zero_index.first, zero_index.second + 1});
            swap(board[zero_index.first][zero_index.second],
                 board[zero_index.first][zero_index.second + 1]);
        }
    }

    string board2string(vector<vector<int>> board)
    {
        string board_string = "";
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                board_string += to_string(board[i][j]);
        return board_string;
    }
};
// ! DFS
int main(void)
{
    Solution solution;
    vector<vector<int>> puzzle = {{1, 2, 3}, {4, 0, 5}};
    int min_step = solution.slidingPuzzle(puzzle);
    cout << min_step << endl;
}