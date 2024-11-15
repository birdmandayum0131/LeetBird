#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1; // * non-sorted aray [left, right)
        // init right
        while (right > 0 && arr[right - 1] <= arr[right])
            right--;

        int min_subarray_len = right - left;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left]))
        {
            while (arr[right] < arr[left] && right < n)
                right++;
            min_subarray_len = min(min_subarray_len, right - left - 1);
            left++;
        }
        return min_subarray_len;
    }
};
int main(void)
{
    Solution solution;
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
    int output = solution.findLengthOfShortestSubarray(arr);
    cout << output << endl;
}