#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<tuple<int, long long>> index_stack;
        long long count = 0;
        int min_len = n + 1;
        for (int i = 0; i < n; i++)
        {
            count = max(0LL, count + nums[i]);
            if (count >= k)
            {
                int left = 0, right = index_stack.size(); // ? [left, right)
                while (left < right - 1)
                {
                    int mid = (left + right) / 2;
                    if (count - get<1>(index_stack[mid]) >= k)
                        left = mid;
                    else
                        right = mid;
                }
                if (left == right || count - get<1>(index_stack[left]) < k)
                    min_len = min(min_len, i + 1);
                else
                    min_len = min(min_len, i - get<0>(index_stack[left]));
            }
            push_monotonic(index_stack, {i, count});
            if (min_len == 1)
                break;
        }
        return min_len > n ? -1 : min_len;
    }

  private:
    void push_monotonic(deque<tuple<int, long long>> &index_stack, tuple<int, long long> index)
    {
        while (index_stack.size() > 0 && get<1>(index_stack.back()) >= get<1>(index))
            index_stack.pop_back();
        index_stack.push_back(index);
    }
};
// ! same algorithm with solution 2 but more concise.
int main(void)
{
    Solution solution;
    vector<int> nums = {-34, 37, 51, 3, -12, -50, 51, 100, -47, 99, 34, 14, -13, 89, 31, -14, -44, 23, -38, 6};
    int k = 151;
    int result = solution.shortestSubarray(nums, k);
    cout << result << endl;
}