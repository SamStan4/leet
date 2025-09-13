#include <queue>
#include <vector>
#include <unordered_map>

class Solution {

  private:

    int windowSize{};
    int smallNumsSize{};
    int largeNumsSize{};
    std::unordered_map<int, int> deadNums{};
    std::priority_queue<int, std::vector<int>, std::less<int>> smallNums{};
    std::priority_queue<int, std::vector<int>, std::greater<int>> largeNums{};

    /**
     * Note that we assume that the two queues
     * are "balanced" before we enter this method
     */
    void pushElement(const std::vector<int>& nums,
                     const int idx);

  public:

    std::vector<double> medianSlidingWindow(const std::vector<int>& nums,
                                            const int k);
};

void Solution::pushElement(const std::vector<int>& nums,
                           const int idx) {

  if (idx >= this->windowSize) {
    ++this->deadNums[nums[idx - this->windowSize]];
  }

  
}

std::vector<double> Solution::medianSlidingWindow(const std::vector<int>& nums,
                                                  const int k) {
  this->windowSize = k;
}





















































































































































































































































































































































































































































































































































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