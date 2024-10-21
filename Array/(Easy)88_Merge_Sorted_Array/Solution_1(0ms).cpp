#include <vector>
#include <tuple>
#include <iostream>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(m + n);
        for (int i = 0, j = 0, k = 0; i < m + n; i++)
        {
            if (j == m && k == n)
            {
                break;
            }
            else if (j == m)
            {
                result[i] = nums2[k];
                k++;
            }
            else if (k == n)
            {
                result[i] = nums1[j];
                j++;
            }
            else
            {
                if (nums1[j] < nums2[k])
                {
                    result[i] = nums1[j];
                    j++;
                }
                else
                {
                    result[i] = nums2[k];
                    k++;
                }
            }
        }
        for (int i = 0; i < m + n; i++)
            nums1[i] = result[i];
    }
};
int main(void)
{
    Solution solution;
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2{2, 5, 6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << ",";
    cout << "\b " << endl;
}