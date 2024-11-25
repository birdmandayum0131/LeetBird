#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
  public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        unordered_set<string> min_step_set;
        string target = "123450";
        pair<int, int> zero_index;
        int min_step = solvePuzzle(min_step_set, board, target);
        return min_step;
    }

  private:
    int solvePuzzle(unordered_set<string> &min_step_set, vector<vector<int>> puzzle, string target)
    {
        queue<tuple<vector<vector<int>>, int>> puzzle_queue;
        puzzle_queue.push({puzzle, 0});
        while (puzzle_queue.size() > 0)
        {
            auto [board, step] = puzzle_queue.front();
            puzzle_queue.pop();
            auto [current_state, zero_index] = convert_and_find_zero(board);
            if (min_step_set.find(current_state) != min_step_set.end())
                continue;
            if (current_state == target)
                return step;
            min_step_set.insert(current_state);

            int target_row = zero_index.first == 0 ? 1 : 0;
            swap(board[zero_index.first][zero_index.second], board[target_row][zero_index.second]);
            puzzle_queue.push({board, step + 1});
            swap(board[zero_index.first][zero_index.second], board[target_row][zero_index.second]);

            if (zero_index.second > 0)
            {
                swap(board[zero_index.first][zero_index.second],
                     board[zero_index.first][zero_index.second - 1]);
                puzzle_queue.push({board, step + 1});
                swap(board[zero_index.first][zero_index.second],
                     board[zero_index.first][zero_index.second - 1]);
            }

            if (zero_index.second < board[0].size() - 1)
            {
                swap(board[zero_index.first][zero_index.second],
                     board[zero_index.first][zero_index.second + 1]);
                puzzle_queue.push({board, step + 1});
                swap(board[zero_index.first][zero_index.second],
                     board[zero_index.first][zero_index.second + 1]);
            }
        }
        return -1;
    }

    tuple<string, pair<int, int>> convert_and_find_zero(vector<vector<int>> board)
    {
        pair<int, int> zero_index;
        string board_string = "";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board_string += to_string(board[i][j]);
                if (board[i][j] == 0)
                    zero_index = {i, j};
            }
        }
        return {board_string, zero_index};
    }
};
// ! BFS
int main(void)
{
    Solution solution;
    vector<vector<int>> puzzle = {{1, 2, 3}, {4, 0, 5}};
    int min_step = solution.slidingPuzzle(puzzle);
    cout << min_step << endl;
}