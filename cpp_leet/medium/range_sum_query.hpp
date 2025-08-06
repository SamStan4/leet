#include <vector>
#include <type_traits>
#include <cassert>
#include <ios>
#include <iostream>

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
     * @brief This is a helper function for the the  query public method.
     * 
     * @param i The curent index in the segment tree buffer.
     * @param l The left bound of the curent segment (inclusive).
     * @param r The right bound of the curent segment (inclusive).
     * @param ql The left bound of the query range (inclusive).
     * @param qr The right bound of the query range (inclusive).
     * @return T The segment sum.
     */
    T query(const size_t i, const size_t l, const size_t r, const size_t ql, const size_t qr);

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
     * @brief This allows us to perform a query on the vector. I.e. a range sum.
     * 
     * @param l The left bound on the segment that we are taking the sum of (inclusive).
     * @param r The right bound on the segment that we are taking the sum of (inclusive).
     * @return T This is the range sum.
     */
    T query(const size_t l, const size_t r);
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

  this->m_segmentTreeBuffer[i] = this->m_segmentTreeBuffer[leftChildIdx] + this->m_segmentTreeBuffer[rightChildIdx];
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

  this->m_segmentTreeBuffer[i] = this->m_segmentTreeBuffer[leftChildIdx] + this->m_segmentTreeBuffer[rightChildIdx];
}

template<typename T>
T SegmentTree<T>::query(const size_t i, const size_t l, const size_t r, const size_t ql, const size_t qr) {

  if (qr < l || r < ql) {
    return T{};
  }

  if (ql <= l && r <= qr) {
    return this->m_segmentTreeBuffer[i];
  }

  const size_t midPointIdx = (l + r) / 2;
  const size_t leftChildIdx = 2 * i + 1;
  const size_t rightChildIdx = 2 * i + 2;

  return this->query(leftChildIdx, l, midPointIdx, ql, qr) + this->query(rightChildIdx, midPointIdx + 1, r, ql, qr);
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
T SegmentTree<T>::query(const size_t l, const size_t r) {

  assert(l >= 0 && r < this->m_segmentTreeSize && "index out of bounds in SegmentTree::query");
  assert(l <= r && "invalid query");
  
  return this->query(0, 0, this->m_segmentTreeSize - 1, l, r);
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

class NumArray {

  private:

    /**
     * Num Array data members:
     *  - tree: this is the segment tree that makes this problem possible in good time :)
     */
    SegmentTree<int> tree;

  public:

    /**
     * @brief Construct a new Num Array object. Constructor for NumArray.
     * 
     * @param nums The "NumArray" that we are going to be performing range sum queries on and mutating.
     */
    NumArray(std::vector<int>& nums);
    
    /**
     * @brief This method updates a number in the nums vector.
     * 
     * @param index The index of the number that we are going to update.
     * @param val The new value that we are going to set the index to.
     */
    void update(int index, int val);
    
    /**
     * @brief This method returns the range sum of the segment.
     * 
     * @param left This is the left bound of the segment (inclusive).
     * @param right This is the left bound of the segment (inclusive).
     * @return int The sum of the elements between left and right.
     */
    int sumRange(int left, int right);
};

NumArray::NumArray(std::vector<int>& nums) : tree(nums) {
}

void NumArray::update(int index, int val) {
  this->tree.update(index, val);
}

int NumArray::sumRange(int left, int right) {
  return this->tree.query(left, right);
}

#define USE_FAST_IO

#ifdef USE_FAST_IO
  static auto give_me_fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0b00000000000000000000000000000000;
  } ();
#endif