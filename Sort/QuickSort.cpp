#include <vector>
#include <tuple>
class Solution
{
public:
    void quickSortNonRec(std::vector<int> &array)
    {
        std::vector<std::tuple<int, int>> partionPairs;
        partionPairs.push_back(std::make_tuple(0, array.size() - 1));
        while (int n = partionPairs.size())
        {
            std::tuple<int, int> pair = partionPairs[n - 1];
            partionPairs.pop_back();
            int start = std::get<0>(pair);
            int end = std::get<1>(pair);
            int p = start;
            for (int i = p + 1; i <= end; i++)
            {
                if (array[i] < array[start])
                {
                    p++;
                    int tmp = array[p];
                    array[p] = array[i];
                    array[i] = tmp;
                }
            }
            int tmp = array[start];
            array[start] = array[p];
            array[p] = tmp;

            if (p - 1 > start)
                partionPairs.push_back(std::make_tuple(start, p - 1));
            if (end > p + 1)
                partionPairs.push_back(std::make_tuple(p + 1, end));
        }
    }
};