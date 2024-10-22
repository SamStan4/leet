#pragma once

#include "./../imports.hpp"

class DynamicArray {
private:
    int* _memoryPointer,
         _memoryCapacity,
         _inUse;
    void check(int i) {
        if (i >= this->_inUse) {
            throw std::invalid_argument("Error, cannot access element at index\n");
        } else if (i < 0) {
            throw std::invalid_argument("Error, cannot access negative element index\n");
        }
    }
public:

    DynamicArray(int capacity) {
        this->_memoryPointer = (int*) new int[capacity];
        this->_memoryCapacity = capacity;
        this->_inUse = 0;
    }

    ~DynamicArray() {
        if (!this->_memoryPointer) {
            return;
        }
        delete this->_memoryPointer;
    }

    int get(int i) {
        this->check(i);
        return this->_memoryPointer[i];
    } 

    void set(int i, int n) {
        this->check(i);
        this->_memoryPointer[i] = n;
    }

    void pushback(int n) {
        if (_inUse >= this->_memoryCapacity) {
            this->resize();
        }
        this->_memoryPointer[_inUse++] = n;
    }

    int popback() {
        if (this->_inUse <= 0) {
            throw std::invalid_argument("Error, dynamic array was empty");
        }
        return this->_memoryPointer[--this->_inUse];
    }

    void resize() {
        this->_memoryCapacity *= 2;
        int* newMemPtr = (int*) new int[this->_memoryCapacity];
        for (int i = 0; i < this->_inUse; ++i) {
            newMemPtr[i] = this->_memoryPointer[i];
        }
        int* temp = this->_memoryPointer;
        delete []this->_memoryPointer;
        this->_memoryPointer = newMemPtr;
    }

    int getSize() {
        return this->_inUse;
    }

    int getCapacity() {
        return this->_memoryCapacity;
    }
};