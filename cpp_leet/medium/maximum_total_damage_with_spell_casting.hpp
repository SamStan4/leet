#include <vector>
#include <algorithm>
#include <limits>
#include <ios>
#include <iostream>

struct spell_power_data {
  private:

  public:

    int spell_power;
    int spell_power_freq;

    spell_power_data(const int new_spell_power, const int new_spell_power_freq = 1)
      : spell_power(new_spell_power), spell_power_freq(new_spell_power_freq) {}

    long long get_total_power_output() const {
      return static_cast<long long>(this->spell_power) * static_cast<long long>(this->spell_power_freq);
    }

    void increment_freq() { ++this->spell_power_freq; }
};

class Solution {
  private:

    std::vector<spell_power_data> spell_power_info;

    size_t get_next_idx(const size_t cur_idx) {
      const int min_power = this->spell_power_info[cur_idx].spell_power + 3;
      for (size_t i = cur_idx + 1; i < this->spell_power_info.size(); ++i)
        if (this->spell_power_info[i].spell_power >= min_power)
          return i;
      return std::numeric_limits<size_t>::max();
    }

    void populate_spell_power_info(std::vector<int>& spell_powers) {
      std::sort(spell_powers.begin(), spell_powers.end());
      if (spell_powers.size() == 0ul)
        return;
      this->spell_power_info.emplace_back(spell_powers[0]);
      for (size_t i = 1; i < spell_powers.size(); ++i)
        if (spell_powers[i] == spell_powers[i - 1])
          this->spell_power_info.back().increment_freq();
        else
          this->spell_power_info.emplace_back(spell_powers[i]);
    }

    long long do_the_dp() {
      std::vector<long long> dp_cache(this->spell_power_info.size(), -1ll);
      return this->do_the_dp(dp_cache, 0ul);
    }

    long long do_the_dp(std::vector<long long>& dp_cache, const size_t idx) {
      if (idx >= this->spell_power_info.size()) return 0;
      if (dp_cache[idx] != -1) return dp_cache[idx];
      dp_cache[idx] = std::max(
        this->do_the_dp(dp_cache, idx + 1),
        this->spell_power_info[idx].get_total_power_output() + this->do_the_dp(dp_cache, this->get_next_idx(idx))
      );
      return dp_cache[idx];
    }

  public:

    long long maximumTotalDamage(std::vector<int>& spell_powers) {
      this->populate_spell_power_info(spell_powers);
      return this->do_the_dp();
    }
};

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();