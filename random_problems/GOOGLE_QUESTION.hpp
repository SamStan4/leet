#pragma once

#include "./../imports.hpp"

class Store
{
private:
    vector<int> itemVector;
    unordered_map<int, int> itemToIdxMap;

public:
    Store()
    {
        this->itemToIdxMap.clear();
        this->itemVector.clear();
    }

    ~Store()
    {
        this->itemToIdxMap.clear();
        this->itemVector.clear();
    }

    void InsertItem(int newItem)
    {
        // first make sure that there is not goint to be a duplicate in the set of items
        if (this->itemToIdxMap.find(newItem) != this->itemToIdxMap.end())
        {
            return;
        }

        this->itemToIdxMap[newItem] = this->itemVector.size();
        this->itemVector.push_back(newItem);
        
    }

    void RemoveItem(int targetItem)
    {
        // make sure that the item exists first
        if (this->itemToIdxMap.find(targetItem) == this->itemToIdxMap.end())
        {
            return;
        }

        int swappedVal = this->itemVector.back();
        this->itemToIdxMap[swappedVal] = this->itemToIdxMap[targetItem];
        this->itemVector[this->itemToIdxMap[targetItem]] = swappedVal;
        this->itemToIdxMap.erase(targetItem);
        this->itemVector.pop_back();
    }

    int getRandomValue(void)
    {
        if (this->itemVector.size() == 0)
        {
            return 0;   
        }

        return this->itemVector[rand() % (int)this->itemVector.size()];
    }
};