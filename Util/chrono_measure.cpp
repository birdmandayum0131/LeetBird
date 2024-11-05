#include <chrono>
#include <functional>
#include <iostream>

using namespace std;
auto measure = [](auto &&function) -> decltype(auto) {
    return [=](auto &&...parameters) mutable -> decltype(auto) {
        const std::chrono::steady_clock::time_point startTimePoint =
            std::chrono::steady_clock::now();

        decltype(auto) result = function(std::forward<decltype(parameters)>(parameters)...);

        const std::chrono::steady_clock::time_point stopTimePoint =
            std::chrono::steady_clock::now();

        const std::chrono::milliseconds timeSpan =
            std::chrono::duration_cast<std::chrono::milliseconds>(stopTimePoint - startTimePoint);

        std::cout << "Computation took " << timeSpan.count() << " milliseconds." << std::endl;

        return result;
    };
};

class Solution
{
  public:
    int minChanges(string s)
    {
        int count = 0;
        for (int j = 0; j < 100000000; j += 2)
        {
            int i = j % s.length();
            count++;
        }
        return count;
    }
};

int main(void)
{
    Solution solution;
    string s = "1001";
    auto function = bind(&Solution::minChanges, solution, std::placeholders::_1);
    decltype(auto) result = measure(function)(s);
    std::cout << "Result: " << result << " " << &result << std::endl;
}