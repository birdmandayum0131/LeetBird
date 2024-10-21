#include <vector>
#include <utility>
#include <iostream>
class Solution
{
public:
    void quickSortNonRec(std::vector<int> &array)
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
                    std::swap(array[++p], array[i]);

            std::swap(array[start], array[p]);

            if (p - 1 > start)
                partions.push_back({start, p - 1});
            if (end > p + 1)
                partions.push_back({p + 1, end});
        }
    }
};

int main(void)
{
    Solution solution;
    std::vector<int> numbers = {6, 5, 4, 3, 2, 1, 0};
    solution.quickSortNonRec(numbers);
    for (int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << ",";
    std::cout << "\b " << std::endl;
}