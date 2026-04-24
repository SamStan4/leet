#include <string>
#include <vector>

class Solution {
private:
    inline static std::vector<std::string> cache;

    static std::string get_next(const std::string& cur) {

        const int n = static_cast<int>(cur.size());

        int  freq   = 1;
        char letter = cur[0];

        std::string next;

        for (int i = 1; i < n; ++i) {

            if (cur[i] != cur[i - 1]) {

                next += std::to_string(freq);
                next += letter;

                freq   = 1;
                letter = cur[i];

                continue;
            }

            ++freq;
        }

        if (freq > 0) {
            next += std::to_string(freq);
            next += letter;
        }

        return next;
    }

public:
    static std::string countAndSay(int n) {

        while (static_cast<int>(Solution::cache.size()) < n) {
            
            if (Solution::cache.empty()) {
                Solution::cache.emplace_back("1");
                continue;
            }

            Solution::cache.push_back(Solution::get_next(Solution::cache.back()));
        }

        return Solution::cache[n - 1];
    }
};