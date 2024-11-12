#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        vector<vector<int>> new_intervals;
        int i;
        for (i = 0; i < n; i++)
        {
            if (intervals[i][1] < newInterval[0])
                new_intervals.push_back(intervals[i]);
            else
                break;
        }
        if (i == n)
        {
            new_intervals.push_back(newInterval);
            return new_intervals;
        }

        int start;
        if (intervals[i][0] <= newInterval[1])
        {
            start = min(intervals[i][0], newInterval[0]);
            for (; i < n; i++)
                if (intervals[i][0] > newInterval[1])
                    break;
            new_intervals.push_back({start, max(intervals[i - 1][1], newInterval[1])});
        }
        else
            new_intervals.push_back(newInterval);

        for (; i < n; i++)
            new_intervals.push_back(intervals[i]);
        return new_intervals;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> intervals = {{1, 5}};
    vector<int> newInterval = {0, 0};
    vector<vector<int>> output_intervals = solution.insert(intervals, newInterval);
    cout << "[";
    for (auto interval : output_intervals)
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    cout << "\b\b]";
}