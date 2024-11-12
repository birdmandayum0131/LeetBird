#include <iostream>
#include <map>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        // statistics every price in items and queries
        map<int, int> max_cp_map; //* <price, max_beauty>, need to be orderd.
        for (auto item : items)
            if (max_cp_map[item[0]] < item[1])
                max_cp_map[item[0]] = item[1];
        for (auto query : queries)
            max_cp_map[query] += 0;
        for (auto it = next(max_cp_map.begin()); it != max_cp_map.end(); it++)
            (*it).second = max((*prev(it)).second, (*it).second);
        vector<int> result(queries.size());
        for (int i = 0; i < result.size(); i++)
            result[i] = max_cp_map[queries[i]];
        return result;
    }
};
int main(void)
{
    Solution solution;
    vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    vector<int> output = solution.maximumBeauty(items, queries);
    for (auto answer : output)
        cout << answer << ", ";
    cout << "\b\b " << endl;
}