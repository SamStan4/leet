#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>

class DataStreamMedianFinder {
  private:
    size_t lNumsSize{};                                                    // the size of the lNums queue - the number of elements marked for lazy deletion
    size_t rNumsSize{};                                                    // the size of the rNums queue - the number of elements marked for lazy deletion
    std::unordered_map<int, int> numsToPrune{};                            // numbers marked for lazy deletion
    std::priority_queue<int, std::vector<int>, std::less<int>>    lNums{}; // for the smaller half of the numbers
    std::priority_queue<int, std::vector<int>, std::greater<int>> rNums{}; // for the larger  half of the numbers
    void pruneNumbers();
    void balanceQueues();
  public:
    DataStreamMedianFinder() = default;
    ~DataStreamMedianFinder() = default;
    void addElement(int num);
    void deleteElement(int num);
    double getCurMedian() const;
};

void DataStreamMedianFinder::pruneNumbers() {
  while (!this->lNums.empty() && this->numsToPrune[this->lNums.top()] > 0) {
    --this->numsToPrune[this->lNums.top()];
    this->lNums.pop();
  }
  while (!this->rNums.empty() && this->numsToPrune[this->rNums.top()] > 0) {
    --this->numsToPrune[this->rNums.top()];
    this->rNums.pop();
  }
}

void DataStreamMedianFinder::balanceQueues() {
  this->pruneNumbers();
  if (this->rNumsSize < this->lNumsSize) {
    ++rNumsSize, --lNumsSize;
    this->rNums.push(this->lNums.top());
    this->lNums.pop();
  } else if (this->rNumsSize > (this->lNumsSize + 1zu)) {
    ++lNumsSize, --rNumsSize;
    this->lNums.push(this->rNums.top());
    this->rNums.pop();
  }
  this->pruneNumbers();
}

void DataStreamMedianFinder::addElement(int num) {
  this->balanceQueues();
  if (this->rNumsSize == 0UL || num >= this->rNums.top()) {
    this->rNums.push(num);
    ++this->rNumsSize;
  } else {
    this->lNums.push(num);
    ++this->lNumsSize;
  }
  this->balanceQueues();
}

void DataStreamMedianFinder::deleteElement(int num) {
  ++this->numsToPrune[num];
  if (num >= this->rNums.top()) {
    --this->rNumsSize;
  } else {
    --this->lNumsSize;
  }
  this->balanceQueues();
}

double DataStreamMedianFinder::getCurMedian() const {
  const int totalSize = this->lNumsSize + this->rNumsSize;
  if (totalSize % 2UL == 0UL) {
    return (static_cast<double>(this->lNums.top()) + static_cast<double>(this->rNums.top())) / 2.0;
  }
  return static_cast<double>(this->rNums.top());
}

class Solution {
public:
  std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k);
};

std::vector<double> Solution::medianSlidingWindow(std::vector<int>& nums, int k) {
  const int n = static_cast<int>(nums.size());
  DataStreamMedianFinder m;
  for (int i = 0; i < k; ++i)
    m.addElement(nums[i]);
  std::vector<double> answer;
  answer.reserve(n - k + 1);
  answer.push_back(m.getCurMedian());
  for (int i = k; i < n; ++i) {
    m.addElement(nums[i]);
    m.deleteElement(nums[i-k]);
    answer.push_back(m.getCurMedian());
  }
  return answer;
}















































































































































































































































































































































































































































































































































// class Solution {

//   private:

//     int windowSize{};
//     int smallNumsSize{};
//     int largeNumsSize{};
//     std::unordered_map<int, int> deadNums{};
//     std::priority_queue<int, std::vector<int>, std::less<int>>    smallNums{};
//     std::priority_queue<int, std::vector<int>, std::greater<int>> largeNums{};

//     void balanceQueues(
//       void
//     );

//     void lazyDeleteDeadNums(
//       void
//     );

//     void updateTheDeadCount(
//       const std::vector<int>& nums,
//       const int idx
//     );

//     void pushElement(
//       const std::vector<int>& nums,
//       const int idx
//     );

//     double getMedian(
//       void
//     ) const;

//   public:

//     std::vector<double> medianSlidingWindow(
//       const std::vector<int>& nums,
//       const int k
//     );
// };

// void Solution::balanceQueues(
//   void
// ) {

//   while (this->largeNumsSize < this->smallNumsSize) {
//     const int smallNumsTop = this->smallNums.top();
//     this->largeNums.push(smallNumsTop);
//     this->smallNums.pop();
//     if (this->deadNums[smallNumsTop] <= 0) {
//       ++this->largeNumsSize;
//       --this->smallNumsSize;
//     }
//   }

//   while (this->largeNumsSize > (this->smallNumsSize + 1)) {
//     const int largeNumsTop = this->largeNums.top();
//     this->smallNums.push(largeNumsTop);
//     this->largeNums.pop();
//     if (this->deadNums[largeNumsTop] <= 0) {
//       ++this->smallNumsSize;
//       --this->largeNumsSize;
//     }
//   }
// }

// void Solution::lazyDeleteDeadNums(
//   void
// ) {

//   while (!this->smallNums.empty() && this->deadNums[smallNums.top()] > 0) {
//     --this->deadNums[smallNums.top()];
//     this->smallNums.pop();
//   }

//   while (!this->largeNums.empty() && this->deadNums[largeNums.top()] > 0) {
//     --this->deadNums[largeNums.top()];
//     this->largeNums.pop();
//   }
// }

// void Solution::updateTheDeadCount(
//   const std::vector<int>& nums,
//   const int idx
// ) {

//   if (idx < this->windowSize) {
//     return;
//   }

//   const int deadNum = nums[idx - this->windowSize];

//   ++this->deadNums[deadNum];

//   if (deadNum >= this->largeNums.top()) {
//     --largeNumsSize;
//   } else {
//     --smallNumsSize;
//   }
// }

// void Solution::pushElement(
//   const std::vector<int>& nums,
//   const int idx
// ) {

//   this->updateTheDeadCount(nums, idx);

//   const int newNum = nums[idx];

//   if (this->largeNumsSize == 0 || newNum >= this->largeNums.top()) {
//     ++this->largeNumsSize;
//     this->largeNums.push(newNum);
//   } else {
//     ++this->smallNumsSize;
//     this->smallNums.push(newNum);
//   }

//   for (int i = 0; i < 1000; ++i) {  
//   this->lazyDeleteDeadNums();

//   this->balanceQueues();
//   }
// }

// double Solution::getMedian(
//   void
// ) const {
//   if (this->windowSize % 2 == 0) {
//     return (static_cast<double>(this->largeNums.top()) + static_cast<double>(this->smallNums.top())) / 2.0;
//   }
//   return static_cast<double>(this->largeNums.top());
// }

// std::vector<double> Solution::medianSlidingWindow(
//   const std::vector<int>& nums,
//   const int k
// ) {
//   const int n = static_cast<int>(nums.size());

//   this->windowSize = k;

//   for (int i = 0; i < this->windowSize; ++i) {
//     this->pushElement(
//       nums, i
//     );
//   }

//   std::vector<double> answer;
//   answer.reserve(n - this->windowSize + 1);
//   answer.push_back(this->getMedian());

//   for (int i = this->windowSize; i < n; ++i) {
//     this->pushElement(nums, i);
//     answer.push_back(this->getMedian());
//   }

//   return answer;
// }



// class Solution {

//   private:

//     std::unordered_map<int, int>                                  deadNumbers{}; // numbers marked for lazy deletion
//     std::priority_queue<int, std::vector<int>, std::less<int>>    lowNumbers {}; // max heap for the smaller half of numbers in the k-wide window
//     std::priority_queue<int, std::vector<int>, std::greater<int>> highNumbers{}; // min heap for the larger half of numbers in the k-wide window

//     void pushNumber(
//       const std::vector<int>& nums,
//       const int k,
//       const int i
//     );

//     void balanceQueues(
//       void
//     );

//     void getRidOfTheDead(
//       void
//     );

//     double getCurMedian(
//       const int k
//     );

//   public:

//     std::vector<double> medianSlidingWindow(
//       const std::vector<int>& nums,
//       const int k
//     );
// };

// void Solution::balanceQueues(
//   void
// ) {

//   if (this->highNumbers.size() < this->lowNumbers.size()) {

//     this->highNumbers.push(this->lowNumbers.top());
//     this->lowNumbers.pop();

//   } else if (this->highNumbers.size() > (this->lowNumbers.size() + 1uz)) {

//     this->lowNumbers.push(this->highNumbers.top());
//     this->highNumbers.pop();

//   }
// }

// void Solution::getRidOfTheDead(
//   void
// ) {

//   while (
//     this->deadNumbers[this->lowNumbers.top()] > 0 ||
//     this->deadNumbers[this->highNumbers.top()] > 0
//   ) {

//     if (this->deadNumbers[this->lowNumbers.top()] > 0) {
//       --this->deadNumbers[this->lowNumbers.top()];
//       this->lowNumbers.pop();
//     } else {
//       --this->deadNumbers[this->highNumbers.top()];
//       this->highNumbers.pop();
//     }

//     this->balanceQueues();
//   }
// }

// void Solution::pushNumber(
//   const std::vector<int>& nums,
//   const int k,
//   const int i
// ) {

//   const int n = nums[i];

//   if (this->highNumbers.empty() || n >= this->highNumbers.top()) {
//     this->highNumbers.push(n);
//   } else {
//     this->lowNumbers.push(n);
//   }

//   this->balanceQueues();

//   if (i >= k) {
//     ++this->deadNumbers[nums[i - k]];

//     this->getRidOfTheDead();
//   }
// }

// double Solution::getCurMedian(
//   const int k
// ) {

//   if (k % 2 == 0) {
//     return static_cast<double>(this->lowNumbers.top() + this->highNumbers.top()) / 2.0;
//   } else {
//     return static_cast<double>(this->highNumbers.top());
//   }
// }


// std::vector<double> Solution::medianSlidingWindow(
//   const std::vector<int>& nums,
//   const int k
// ) {

//   const int n = static_cast<int>(nums.size());

//   for (int i = 0; i < k; ++i) {
//     this->pushNumber(nums, k, i);
//   }

//   std::vector<double> answer;
//   answer.reserve(n - k + 1);
  
//   answer.push_back(this->getCurMedian(k));

//   for (int i = k; i < n; ++i) {
//     this->pushNumber(nums, k, i);
//     answer.push_back(this->getCurMedian(k));
//   }

//   return answer;
// }











// class Solution {
// private:
//   void pushElement(
//     const int newElement,
//     std::unordered_map<int, int>& deadMap,
//     std::priority_queue<int>& maxHeap,
//     std::priority_queue<int, std::vector<int>, std::greater<int>>& minHeap
//   );
// public:
//   std::vector<double> medianSlidingWindow(
//     std::vector<int>& nums,
//     int k
//   );
// };

// void pushElement(
//   const int newElement,
//   std::unordered_map<int, int>& deadMap,
//   std::priority_queue<int>& maxHeap,
//   std::priority_queue<int, std::vector<int>, std::greater<int>>& minHeap
// ) {

//   // Place
//   if (minHeap.size() == 0uz || newElement >= minHeap.top()) {
//     minHeap.push(newElement);
//   } else {
//     maxHeap.push(newElement);
//   }

//   // Balance
//   if (minHeap.size() < maxHeap.size()) {
//     minHeap.push(maxHeap.top());
//     maxHeap.pop();
//   } else if (minHeap.size() > (maxHeap.size() + 1)) {
//     maxHeap.push(minHeap.top());
//     minHeap.pop();
//   }

//   // Kill dead elements
//   while (
//     (!maxHeap.empty() && deadMap.find(maxHeap.top()) != deadMap.end()) ||
//     (!minHeap.empty() && deadMap.find(minHeap.top()) != deadMap.end()) 
//   ) {

//   }
// }


// std::vector<double> Solution::medianSlidingWindow(
//   std::vector<int>& nums,
//   int k
// ) {
//   const int n = static_cast<int>(nums.size());

//   std::unordered_map<int, int>                                  deadMap; // for lazy deletion from the two priority queues
//   std::priority_queue<int>                                      maxHeap; // put the smaller half of elements in here
//   std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // put the larger half of elements here

//   for (int i  = 0; i < k; ++i) {

//   }

//   std::vector<double> answer;

// }