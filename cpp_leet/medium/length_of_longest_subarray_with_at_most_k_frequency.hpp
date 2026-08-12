// NOLINTBEGIN(misc-definitions-in-headers)

#if 0

#include <vector>
#include <list>
#include <unordered_map>

// Terrible solution

class Solution
{
private:
    struct Node
    {
        Node(const int new_key) : key(new_key), frequency(0) {};
        int key;
        int frequency;
    };
public:
    static int maxSubarrayLength(
        const std::vector<int>& nums,
        int k);
};

int Solution::maxSubarrayLength(
    const std::vector<int>& nums,
    int k)
{
    const int n = static_cast<int>(nums.size());

    if (n == 0) return 0;

    std::list<Solution::Node> list;
    std::unordered_map<int, std::list<Solution::Node>::iterator> map;

    int i = 0; // Forward pointer
    int j = 0; // Tail pointer

    int max_length = 0;

    while (i < n)
    {
        // Take nums[i] into the current window

        auto map_iter = map.find(nums[i]);

        if (map_iter == map.end())
        {
            list.emplace_front(nums[i]);
            map_iter = map.emplace(nums[i], list.begin()).first;
        }

        auto list_iter = map_iter->second;

        ++list_iter->frequency;

        // Move the updated node to it's appropriate position
        for (
            auto list_iter_next = std::next(list_iter);
            list_iter_next != list.end();
            list_iter_next = std::next(list_iter))
        {
            if (list_iter->frequency > list_iter_next->frequency)
            {
                list.splice(list_iter, list, list_iter_next);
            }
            else
            {
                break;
            }
        }

        ++i;

        // Shrink window until condition is satisfied

        while (!list.empty() && list.back().frequency > k)
        {
            auto map_iter = map.find(nums[j]);
            auto list_iter = map_iter->second;

            --list_iter->frequency;

            if (list_iter->frequency == 0)
            {
                list.erase(list_iter);
                map.erase(map_iter);
            }
            else if (list_iter != list.begin())
            {
                auto list_iter_prev = std::prev(list_iter);

                if (list_iter_prev->frequency > list_iter->frequency)
                {
                    list.splice(list_iter_prev, list, list_iter);
                }
            }
            
            ++j;
        }

        max_length = std::max(max_length, i - j);
    }

    return max_length;
}

#else

// Much better solution

#include <vector>
#include <unordered_map>

class Solution
{
public:
    static int maxSubarrayLength(
        const std::vector<int>& nums,
        int k);
};

int Solution::maxSubarrayLength(
    const std::vector<int>& nums,
    int k)
{
    const int n = static_cast<int>(nums.size());
    std::unordered_map<int, int> map;

    int i = 0;
    int j = 0;

    int max_length = 0;

    while (i < n)
    {
        // Bring the element to the right of the window into the window

        auto it_i = map.find(nums[i]);

        if (it_i == map.end())
        {
            it_i = map.emplace(nums[i], 1).first;
        }
        else
        {
            ++it_i->second;
        }

        ++i;

        // Remove elements from window's tail until condition is satisfied

        while (it_i->second > k)
        {
            auto it_j = map.find(nums[j]);
            
            if (--it_j->second == 0)
            {
                map.erase(it_j);
            }

            ++j;
        }

        max_length = std::max(max_length, i - j);
    }

    return max_length;
}

#endif

// NOLINTEND(misc-definitions-in-headers)