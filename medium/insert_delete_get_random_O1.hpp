#include "../imports.hpp"

class RandomizedSet {
private:
    std::unordered_map<int, int> mp;
    std::vector<int> vec;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (this->mp.find(val) != this->mp.end()) {
            return false;
        }
        this->mp[val] = this->vec.size();
        this->vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (this->mp.find(val) == this->mp.end()) {
            return false;
        }
        this->vec[this->mp[val]] = this->vec.back();
        this->mp[this->vec.back()] = this->mp[val];
        this->mp.erase(val);
        this->vec.pop_back();
        return true;
    }
    
    int getRandom() {
        return this->vec[rand() % this->vec.size()];
    }
};