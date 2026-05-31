// NOLINTBEGIN(misc-definitions-in-headers)

#include <vector>
#include <algorithm> // IWYU pragma: keep
#include <queue>     // IWYU pragma: keep
#include <array>     // IWYU pragma: keep

class Solution
{
public:
    static bool asteroidsDestroyed(
        int mass,
        std::vector<int>& asteroids);
private:
    using ull = unsigned long long;
    using mpq = std::priority_queue<int, std::vector<int>, std::greater<int>>;
    static constexpr size_t maxAsteroidMass = static_cast<size_t>(10e5 + 1);
};

#if 1

bool Solution::asteroidsDestroyed(
    int mass,
    std::vector<int>& asteroids)
{
    Solution::ull planetMass = static_cast<Solution::ull>(mass);

    std::sort(asteroids.begin(), asteroids.end());

    for (const int asteroid : asteroids)
    {
        Solution::ull asteroidMass = static_cast<Solution::ull>(asteroid);

        if (asteroidMass > planetMass)
        {
            return false;
        }

        planetMass += asteroidMass;
    }

    return true;
}

#elif 0

bool Solution::asteroidsDestroyed(
    int mass,
    std::vector<int>& asteroids)
{
    Solution::ull planetMass = static_cast<Solution::ull>(mass);

    Solution::mpq asteroidMasses(asteroids.begin(), asteroids.end());

    while (!asteroidMasses.empty())
    {
        Solution::ull asteroidMass = static_cast<Solution::ull>(asteroidMasses.top());

        if (asteroidMass > planetMass)
        {
            return false;
        }

        planetMass += asteroidMass;

        asteroidMasses.pop();
    }

    return true;
}

#else

bool Solution::asteroidsDestroyed(
    int mass,
    std::vector<int>& asteroids)
{
    std::array<int, Solution::maxAsteroidMass> freq{};
    
    Solution::ull planetMass = static_cast<Solution::ull>(mass);

    for (const int asteroid : asteroids)
    {
        ++freq[asteroid];
    }

    for (size_t i = 1; i < Solution::maxAsteroidMass; ++i)
    {        
        if (freq[i] > 0 && i > planetMass)
        {
            return false;
        }

        planetMass += static_cast<Solution::ull>(i) * static_cast<Solution::ull>(freq[i]);
    }

    return true;
}

#endif

// NOLINTEND(misc-definitions-in-headers)
