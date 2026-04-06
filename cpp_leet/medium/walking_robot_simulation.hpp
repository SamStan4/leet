#include <array>
#include <vector>
#include <unordered_set>
#include <ios>
#include <iostream>

class Solution
{
private:
    struct pair_hash
    {
    public:
        size_t operator()(
            const std::pair<int, int>& p) const
        {
            return std::hash<long long>()(
                (static_cast<long long>(p.first) << 32ll) | (p.second & 0xffffffff)
            );
        }
    };
public:
    int robotSim(
        const std::vector<int>& commands,
        const std::vector<std::vector<int>>& obstacles)
    {
        static constexpr std::array<std::pair<int, int>, 4ul> dirs = {
            std::make_pair(0, 1),
            std::make_pair(1, 0),
            std::make_pair(0, -1),
            std::make_pair(-1, 0)
        };

        std::unordered_set<std::pair<int, int>, pair_hash> obstacle_set;
        obstacle_set.reserve(obstacles.size());

        for (const std::vector<int>& obstacle : obstacles)
        {
            obstacle_set.emplace(obstacle[0], obstacle[1]);
        }

        std::pair<int, int> pos = std::make_pair(0, 0);
        int max_dist = 0;
        int dir = 0;

        for (const int command : commands)
        {
            switch (command)
            {
                case -1:
                    dir = (dir + 1) % 4;
                break;
                case -2:
                    dir = (dir + 3) % 4;
                break;
                default:
                    for (int i = 0; i < command; ++i)
                    {
                        pos.first += dirs[dir].first;
                        pos.second += dirs[dir].second;

                        if (obstacle_set.find(pos) != obstacle_set.end())
                        {
                            pos.first -= dirs[dir].first;
                            pos.second -= dirs[dir].second;
                            break;
                        }
                    }

                    max_dist = std::max(max_dist, (pos.first * pos.first) + (pos.second * pos.second));

                break;
            }
        }

        return max_dist;
    }
};

static const int init_func = []() -> int
{
    std::ios_base::sync_with_stdio(false),
        std::cin.tie(nullptr),
        std::cout.tie(nullptr);
    return 0;
} ();