#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void quickSortNonRec(std::vector<std::pair<int, int>> &array)
    {
        std::vector<std::pair<int, int>> partions;
        partions.push_back({0, array.size() - 1});
        while (int n = partions.size())
        {
            std::pair<int, int> part = partions[n - 1];
            partions.pop_back();
            int start = part.first;
            int end = part.second;
            int p = start;

            for (int i = p + 1; i <= end; i++)
                if (array[i] < array[start]) //* only compare first value of pair
                    std::swap(array[p], array[i]);
            std::swap(array[start], array[p]);

            if (p - 1 > start)
                partions.push_back({start, p - 1});
            if (end > p + 1)
                partions.push_back({p + 1, end});
        }
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> sortedIntervals;
        for (int i = 0; i < intervals.size(); i++)
            sortedIntervals.push_back({intervals[i][0], intervals[i][1]});
        quickSortNonRec(sortedIntervals);

        vector<vector<int>> result;
        int start = sortedIntervals[0].first, end = sortedIntervals[0].second;
        for (int i = 1; i < sortedIntervals.size(); i++)
        {
            // push buffer interval
            if (sortedIntervals[i].first > end)
            {
                vector<int> bufferInterval = {start, end};
                result.push_back(bufferInterval);
                start = sortedIntervals[i].first;
            }
            end = std::max(end, sortedIntervals[i].second);
        }
        vector<int> bufferInterval = {start, end};
        result.push_back(bufferInterval);
        return result;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> numbers = {{1, 3}, {2, 6}, {6, 7}, {8, 10}, {15, 18}};
    vector<vector<int>> result = solution.merge(numbers);
    cout << "[";
    for (int i = 0; i < result.size(); i++)
        cout << "[" << result[i][0] << "," << result[i][1] << "],";
    cout << "\b]";
}