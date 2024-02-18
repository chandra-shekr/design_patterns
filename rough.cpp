#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>

int main()
{

    auto even = [](int e)
    { return e % 2 == 0; };

    auto evens = std::views::iota(2, 100) |
                 std::views::filter(even);

    int sum = std::accumulate(evens.begin(), evens.end(), 0);
    std::cout << sum << std::endl;
    return 0;
}