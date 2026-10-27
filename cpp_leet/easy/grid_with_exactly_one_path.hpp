#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::string> createGrid(
        const int m,
        const int n
    );
};

// NOLINTBEGIN(misc-definitions-in-headers)

std::vector<std::string> Solution::createGrid(
    const int m,
    const int n
) {
    std::vector<std::string> grid;
    grid.reserve(m);

    grid.emplace_back(n, '.');

    for (int i = 1; i < m; ++i) {
        grid.emplace_back(n, '#');
        grid.back().back() = '.';
    }

    return grid;
}

// NOLINTEND(misc-definitions-in-headers)