#include <unordered_map>
#include <ios>
#include <iostream>

template <class T>
struct dllNode {
  dllNode<T>* next;
  dllNode<T>* prev;
  T data;
  dllNode();
  dllNode(T newData);
};

template <class T>
dllNode<T>::dllNode()
  : next(nullptr), prev(nullptr), data(T{}) {}

template <class T>
dllNode<T>::dllNode(T newData)
  : next(nullptr), prev(nullptr), data(newData) {}

////////////////////////////////////////////////////////////////////////////////////////////////////////

class LRUCache {
private:
  int capacity;
  std::unordered_map<int, dllNode<std::pair<int, int>>*> mp;
  dllNode<std::pair<int, int>>* head;
  dllNode<std::pair<int, int>>* tail;
  void promoteExistingNodeToFront(dllNode<std::pair<int, int>>* node);
  void addNodeFront(dllNode<std::pair<int, int>>* node);
  void popNodeBack(void);
public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);
};

void LRUCache::promoteExistingNodeToFront(dllNode<std::pair<int, int>>* node) {
  if (node == nullptr) return;
  if (node == this->head) return;
  if (node == this->tail) {
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  this->addNodeFront(node);
}

void LRUCache::addNodeFront(dllNode<std::pair<int, int>>* node) {
  if (node == nullptr) return;
  node->prev = nullptr;
  node->next = this->head;
  if (this->head) this->head->prev = node;
  else this->tail = node;
  this->head = node;
  this->mp[node->data.first] = node;
}

void LRUCache::popNodeBack(void) {
  if (!this->tail) return;
  dllNode<std::pair<int, int>>* temp = this->tail;
  if (this->tail == this->head) {
    this->head = this->tail = nullptr;
  } else {
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
  }
  this->mp.erase(temp->data.first);
  delete temp;
}

LRUCache::LRUCache(int capacity)
  : capacity(capacity), mp(std::unordered_map<int, dllNode<std::pair<int, int>>*>{}), head(nullptr), tail(nullptr) {}

int LRUCache::get(int key) {
  if (this->mp.find(key) == this->mp.end())
    return -1;
  dllNode<std::pair<int, int>>* node = this->mp[key];
  this->promoteExistingNodeToFront(node);
  return node->data.second;
}

void LRUCache::put(int key, int value) {
  if (this->mp.find(key) == this->mp.end()) {
    if (this->capacity == static_cast<int>(this->mp.size())) {
      this->popNodeBack();
    }
    dllNode<std::pair<int, int>>* node = new dllNode<std::pair<int, int>>(std::make_pair(key, value));
    this->addNodeFront(node);
  } else {
    dllNode<std::pair<int, int>>* node = this->mp[key];
    node->data.second = value;
    this->promoteExistingNodeToFront(node);
  }
}

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();