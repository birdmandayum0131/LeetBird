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
        // create dp array
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return find_next_event(dp, events, 0, 0);
    }

  private:
    int find_next_event(vector<vector<int>> &dp, vector<vector<int>> &events, int i, int count)
    {
        if (i >= events.size())
            return 0;
        if (dp[i][count] != -1)
            return dp[i][count];

        int max_value = 0;
        if (count == 2)
            max_value = 0;
        else if (i == events.size() - 1)
            max_value = events[i][2];
        else if (count == 1)
            max_value = max(events[i][2], find_next_event(dp, events, i + 1, count));
        else
        {
            int left = i + 1, right = events.size() - 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (events[mid][0] > events[i][1])
                    right = mid;
                else
                    left = mid + 1;
            }
            if (events[left][0] > events[i][1])
                max_value = max(events[i][2] + find_next_event(dp, events, left, count + 1),
                                find_next_event(dp, events, i + 1, count));
            else
                max_value = max(events[i][2], find_next_event(dp, events, i + 1, count));
        }
        dp[i][count] = max_value;
        return max_value;
    }
};
// ! recursive solution with dp
int main(void)
{
    Solution solution;
    vector<vector<int>> events = {{10, 83, 53}, {63, 87, 45}, {97, 100, 32}, {51, 61, 16}};
    int max_value = solution.maxTwoEvents(events);
    cout << max_value << endl;
}