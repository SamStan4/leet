#include <vector>
#include <limits>

//   $$$$$$\                                                         $$\           $$$$$$$$\                            
//  $$  __$$\                                                        $$ |          \__$$  __|                           
//  $$ /  \__| $$$$$$\   $$$$$$\  $$$$$$\$$$$\   $$$$$$\  $$$$$$$\ $$$$$$\            $$ | $$$$$$\   $$$$$$\   $$$$$$\  
//  \$$$$$$\  $$  __$$\ $$  __$$\ $$  _$$  _$$\ $$  __$$\ $$  __$$\\_$$  _|           $$ |$$  __$$\ $$  __$$\ $$  __$$\ 
//   \____$$\ $$$$$$$$ |$$ /  $$ |$$ / $$ / $$ |$$$$$$$$ |$$ |  $$ | $$ |             $$ |$$ |  \__|$$$$$$$$ |$$$$$$$$ |
//  $$\   $$ |$$   ____|$$ |  $$ |$$ | $$ | $$ |$$   ____|$$ |  $$ | $$ |$$\          $$ |$$ |      $$   ____|$$   ____|
//  \$$$$$$  |\$$$$$$$\ \$$$$$$$ |$$ | $$ | $$ |\$$$$$$$\ $$ |  $$ | \$$$$  |         $$ |$$ |      \$$$$$$$\ \$$$$$$$\ 
//   \______/  \_______| \____$$ |\__| \__| \__| \_______|\__|  \__|  \____/          \__|\__|       \_______| \_______|
//                      $$\   $$ |                                                                                      
//                      \$$$$$$  |                                                                                      
//                       \______/                                                                                       

template<typename T>
struct SegmentTree {

  private:

    static_assert(std::is_arithmetic<T>::value, "SegmentTree only supports numeric types");

    /**
     * Segment tree data members:
     *  - m_segmentTreeSize: The size of the input vector.
     *  - m_segmentTreeBufferSize: The size of the allocated memory buffer.
     *  - m_segmentTreeBuffer: The memory buffer where the actual segment tree is going to be stored.
     */
    const size_t m_segmentTreeSize;
    const size_t m_segmentTreeBufferSize;
    std::vector<T> m_segmentTreeBuffer;

    /**
     * @brief This is a helper function for constructing the segment tree.
     * 
     * @param numbers This is the vector of numbers that the segment tree is being created from.
     * @param i This is the index in the segment tree buffer that is currently being populated.
     * @param l This is the left bound of the segment that we are populating (inclusive).
     * @param r This is the right bound of the segment that we are populating (inclusive).
     */
    void buildSegmentTree(const std::vector<T>& numbers, const size_t i, const size_t l, const size_t r);

    /**
     * @brief This is the helper function of the update public method. It is going to change the
     *        value of one of the elements in the original vector.
     * 
     * @param i This is the curent index that we are at in the segment tree buffer.
     * @param l This is the left bound of the curent segment that we are on (inclusive).
     * @param r This is the right bound of the curent segment that we are on (inclusive).
     * @param pos This is the target position.
     * @param newVal This is what we are going to set the target position to.
     */
    void update(const size_t i, const size_t l, const size_t r, const size_t pos, const T newVal);

    /**
     * @brief Helper function for the public findFirstGreaterEqual method.
     * 
     * @param i This is the curent index of the segment tree buffer.
     * @param l This is the left bound of the curent segment that we are on (inclusive).
     * @param r This is the right bound of the curent segment that we are on (inclusive).
     * @param lowerBound The lower bound of our search query.
     * @return std::pair<bool, size_t> [success, index]
     */
    std::pair<bool, size_t> findFirstGreaterEqual(const size_t i, const size_t l, const size_t r, const T lowerBound);
    
  public:

    /**
     * @brief Construct a new Segment Tree object. Constructor for the segment tree.
     * 
     * @param numbers The numbers that the segment tree is being constructed from.
     */
    SegmentTree(const std::vector<T>& numbers);

    /**
     * @brief Updates one of the numbers from the original vector.
     * 
     * @param pos This is the index of the number that we are going to update.
     * @param newVal This is the value that we are going to set that position to.
     */
    void update(const size_t pos, const T newVal);

    /**
     * @brief This method finds the smallest index in the segment tree that has a value greater than
     *        or equal to lower bound.
     * 
     * @param lowerBound The lower bound of our search query.
     * @return std::pair<bool, size_t> [success, index]
     */
    std::pair<bool, size_t> findFirstGreaterEqual(const T lowerBound);
};

template<typename T>
void SegmentTree<T>::buildSegmentTree(const std::vector<T>& numbers, const size_t i, const size_t l, const size_t r) {

  if (l == r) {
    this->m_segmentTreeBuffer[i] = numbers[l];
    return;
  }

  const size_t midPointIdx = (l + r) / 2;
  const size_t leftChildIdx = 2 * i + 1;
  const size_t rightChildIdx = 2 * i + 2;

  this->buildSegmentTree(numbers, leftChildIdx, l, midPointIdx);
  this->buildSegmentTree(numbers, rightChildIdx, midPointIdx + 1, r);

  this->m_segmentTreeBuffer[i] = std::max(this->m_segmentTreeBuffer[leftChildIdx], this->m_segmentTreeBuffer[rightChildIdx]);
}

template<typename T>
void SegmentTree<T>::update(const size_t i, const size_t l, const size_t r, const size_t pos, const T newVal) {
  
  if (l == r) {
    this->m_segmentTreeBuffer[i] = newVal;
    return;
  }

  const size_t midPointIdx = (l + r) / 2;
  const size_t leftChildIdx = 2 * i + 1;
  const size_t rightChildIdx = 2 * i + 2;

  if (pos <= midPointIdx) {

    this->update(leftChildIdx, l, midPointIdx, pos, newVal);

  } else {

    this->update(rightChildIdx, midPointIdx + 1, r, pos, newVal);
    
  }

  this->m_segmentTreeBuffer[i] = std::max(this->m_segmentTreeBuffer[leftChildIdx], this->m_segmentTreeBuffer[rightChildIdx]);
}

template<typename T>
std::pair<bool, size_t> SegmentTree<T>::findFirstGreaterEqual(const size_t i, const size_t l, const size_t r, const T lowerBound) {
  
  if (this->m_segmentTreeBuffer[i] < lowerBound) {
    return std::make_pair(false, 0);
  }

  if (l == r) {
    return std::make_pair(true, l);
  }

  const size_t midPointIdx = (l + r) / 2;
  const size_t leftChildIdx = 2 * i + 1;

  auto [success, idx] = this->findFirstGreaterEqual(leftChildIdx, l, midPointIdx, lowerBound);

  if (success) {
    return std::make_pair(true, idx);
  }

  const size_t rightChildIdx = 2 * i + 2;

  return this->findFirstGreaterEqual(rightChildIdx, midPointIdx + 1, r, lowerBound);
}

template<typename T>
SegmentTree<T>::SegmentTree(const std::vector<T>& numbers)
  : m_segmentTreeSize(numbers.size()),
    m_segmentTreeBufferSize(this->m_segmentTreeSize * 4),
    m_segmentTreeBuffer(this->m_segmentTreeBufferSize, 0) {

  assert(this->m_segmentTreeSize > 0 && "cannot create a segment tree that is size 0");

  this->buildSegmentTree(numbers, 0, 0, this->m_segmentTreeSize - 1);
}

template<typename T>
void SegmentTree<T>::update(const size_t pos, const T newVal) {

  assert(pos < this->m_segmentTreeSize && "index out of bounds in SegmentTree::update");

  this->update(0, 0, this->m_segmentTreeSize - 1, pos, newVal);
}

template<typename T>
std::pair<bool, size_t> SegmentTree<T>::findFirstGreaterEqual(const T lowerBound) {
  return this->findFirstGreaterEqual(0, 0, this->m_segmentTreeSize - 1, lowerBound);
}

//   $$$$$$\    $$\                         $$\       $$\       $$\                      $$\                               $$\                                               $$\       $$\                         
//  $$  __$$\   $$ |                        \__|      $$ |      $$ |                     $$ |                              $$ |                                              $$ |      $$ |                        
//  $$ /  \__|$$$$$$\   $$\   $$\  $$$$$$\  $$\  $$$$$$$ |      $$ | $$$$$$\   $$$$$$\ $$$$$$\    $$$$$$$\  $$$$$$\   $$$$$$$ | $$$$$$\         $$$$$$\   $$$$$$\   $$$$$$\  $$$$$$$\  $$ | $$$$$$\  $$$$$$\$$$$\  
//  \$$$$$$\  \_$$  _|  $$ |  $$ |$$  __$$\ $$ |$$  __$$ |      $$ |$$  __$$\ $$  __$$\\_$$  _|  $$  _____|$$  __$$\ $$  __$$ |$$  __$$\       $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$ |$$  __$$\ $$  _$$  _$$\ 
//   \____$$\   $$ |    $$ |  $$ |$$ /  $$ |$$ |$$ /  $$ |      $$ |$$$$$$$$ |$$$$$$$$ | $$ |    $$ /      $$ /  $$ |$$ /  $$ |$$$$$$$$ |      $$ /  $$ |$$ |  \__|$$ /  $$ |$$ |  $$ |$$ |$$$$$$$$ |$$ / $$ / $$ |
//  $$\   $$ |  $$ |$$\ $$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |      $$ |$$   ____|$$   ____| $$ |$$\ $$ |      $$ |  $$ |$$ |  $$ |$$   ____|      $$ |  $$ |$$ |      $$ |  $$ |$$ |  $$ |$$ |$$   ____|$$ | $$ | $$ |
//  \$$$$$$  |  \$$$$  |\$$$$$$  |$$$$$$$  |$$ |\$$$$$$$ |      $$ |\$$$$$$$\ \$$$$$$$\  \$$$$  |\$$$$$$$\ \$$$$$$  |\$$$$$$$ |\$$$$$$$\       $$$$$$$  |$$ |      \$$$$$$  |$$$$$$$  |$$ |\$$$$$$$\ $$ | $$ | $$ |
//   \______/    \____/  \______/ $$  ____/ \__| \_______|      \__| \_______| \_______|  \____/  \_______| \______/  \_______| \_______|      $$  ____/ \__|       \______/ \_______/ \__| \_______|\__| \__| \__|
//                                $$ |                                                                                                         $$ |                                                                
//                                $$ |                                                                                                         $$ |                                                                
//                                \__|                                                                                                         \__|                                                                

class Solution {
public:
  int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets);
};

int Solution::numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {

  static constexpr int integer_min = std::numeric_limits<int>::min();

  SegmentTree<int> tree(baskets);
  int numUnplaced = 0;

  for (size_t i = 0; i < fruits.size(); ++i) {

    auto [success, idx] = tree.findFirstGreaterEqual(fruits[i]);

    if (success) {
      tree.update(idx, integer_min);
    } else {
      ++numUnplaced;
    }
  }

  return numUnplaced;

}