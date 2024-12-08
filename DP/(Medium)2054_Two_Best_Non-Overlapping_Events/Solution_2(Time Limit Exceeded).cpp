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

        return find_next_event(events, 0, 0, 0);
    }

  private:
    int find_next_event(vector<vector<int>> &events, int i, int value, int count)
    {
        if (count == 2 || i >= events.size())
            return value;
        if (i == events.size() - 1)
            return value + events[i][2];
        if (count == 1)
            return max(value + events[i][2], value + find_next_event(events, i + 1, value, count));
        // else
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
            return max(find_next_event(events, left, value + events[i][2], count + 1),
                       find_next_event(events, i + 1, value, count));
        else
            return max(events[i][2], find_next_event(events, i + 1, value, count));
    }
};
// ! recursive solution
int main(void)
{
    Solution solution;
    vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    int max_value = solution.maxTwoEvents(events);
    cout << max_value << endl;
}