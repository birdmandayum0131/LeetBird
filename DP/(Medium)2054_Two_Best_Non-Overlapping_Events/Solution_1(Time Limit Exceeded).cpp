#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        // sort the events by starttime -> endtime
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });
        // two pointer solution from begin & end
        int max_value = 0;
        for (int i = 0; i < n; i++)
        {
            int local_max = events[i][2];
            int starttime = events[i][0], endtime = events[i][1], value = events[i][2];
            for (int j = n - 1; j > i; j--)
            {
                if (events[j][0] <= endtime)
                    break;
                local_max = max(local_max, value + events[j][2]);
            }
            max_value = max(max_value, local_max);
        }
        return max_value;
    }
};
// ! O(n^2) solution
int main(void)
{
    Solution solution;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    int max_value = solution.maxTwoEvents(events);
    cout << max_value << endl;
}