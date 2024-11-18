#include <iostream>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
  public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> decrypt_code(n);
        if (k == 0)
            return decrypt_code;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            if (k > 0)
                for (int j = 1; j <= k; j++)
                    count += code[(i + j) % n];
            else
                for (int j = -1; j >= k; j--)
                    count += code[(i + j) % n + ((i + j) >= 0 ? 0 : n)];
            decrypt_code[i] = count;
        }
        return decrypt_code;
    }
};

int main(void)
{
    Solution solution;
    vector<int> code = {2, 4, 9, 3};
    int k = -2;
    vector<int> result = solution.decrypt(code, k);
    for (auto num : result)
        cout << num << ", ";
    cout << "\b\b " << endl;
}