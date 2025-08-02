#include "./../imports.hpp"

struct TrieNode {
  public:
    std::string dirName;
    std::string subTrieSerialization;
    std::unordered_map<std::string, TrieNode*> childrenPtrs;
    TrieNode(const std::string&);
    ~TrieNode();
    void addChild(TrieNode*);
    bool hasChild(const std::string&);
    TrieNode* getChild(const std::string&);
};

TrieNode::TrieNode(const std::string& _dirName)
  : dirName(_dirName), subTrieSerialization(), childrenPtrs() {
}

TrieNode::~TrieNode() {
  for (auto& [_, childPtr] : this->childrenPtrs) {
    delete childPtr;
  }
}

void TrieNode::addChild(TrieNode* _childPtr) {
  if (_childPtr == nullptr) return;
  this->childrenPtrs.emplace(_childPtr->dirName, _childPtr);
}

bool TrieNode::hasChild(const std::string& _childName) {
  return this->childrenPtrs.find(_childName) != this->childrenPtrs.end();
}

TrieNode* TrieNode::getChild(const std::string& _childName) {
  if (this->hasChild(_childName)) {
    return this->childrenPtrs[_childName];
  }
  return nullptr;
}

class Solution {
  private:
    // Data
      TrieNode* root{nullptr};
    // Member functions
      void addPath(const std::vector<std::string>&, TrieNode*, const size_t);
      void addPath(const std::vector<std::string>&);
      void makeTrie(const std::vector<std::vector<std::string>>&);
      std::string serializeTrie(TrieNode*);
      void serializeTrie(void);
  public:
    std::vector<std::vector<std::string>> deleteDuplicateFolder(std::vector<std::vector<std::string>>&);
};

void Solution::addPath(const std::vector<std::string>& _path, TrieNode* _curParentPtr, const size_t _pathIdx) {
  if (_pathIdx >= _path.size()) return;
  if (!_curParentPtr->hasChild(_path[_pathIdx])) {
    _curParentPtr->addChild(new TrieNode(_path[_pathIdx]));
  }
  this->addPath(_path, _curParentPtr->getChild(_path[_pathIdx]), _pathIdx + 1);
}

void Solution::addPath(const std::vector<std::string>& _path) {
  this->addPath(_path, this->root, 0);
}

void Solution::makeTrie(const std::vector<std::vector<std::string>>& _paths) {
  this->root = new TrieNode("/");
  for (const auto& path : _paths) {
    this->addPath(path);
  }
}

std::string Solution::serializeTrie(TrieNode* _curPtr) {
  std::vector<std::pair<std::string, TrieNode*>> sortedChildren(_curPtr->childrenPtrs.begin(), _curPtr->childrenPtrs.end());
  std::sort(sortedChildren.begin(), sortedChildren.end());
  std::string serial = "(";
  for (size_t i = 0; i < sortedChildren.size(); ++i) {
    if (i > 0) serial += ",";
    serial += this->serializeTrie(sortedChildren[i].second);
  }
  serial += ")";
  _curPtr->subTrieSerialization = serial;
  return _curPtr->dirName + serial;
}

void Solution::serializeTrie(void) {
  this->serializeTrie(this->root);
}

std::vector<std::vector<std::string>> Solution::deleteDuplicateFolder(std::vector<std::vector<std::string>>& _paths) {
  this->makeTrie(_paths);
  this->serializeTrie();
  std::cout << this->root->subTrieSerialization << std::endl;
  delete this->root;
  return {};
}

















     



























































// /**
//  * @brief This is LeetCode #1948, Hard, "Delete Duplicate Folders in System."
//  * 
//  * @algorithm
//  *  1.) Build a tree using the given file system.
//  *  2.) Serialize each subtree in the tree using DFS algorithm.
//  *  3.) Hash each one of the subtrees and find duplicates.
//  *  4.) Kill the duplicates.
//  */
// class Solution {
//   private:
//     // Data
//     std::vector<std::string> idxToDirNameLookup;
//     std::unordered_map<std::string, size_t> dirNameToIdxLookup;
//     std::vector<std::vector<size_t>> fileSystemAdjList;
//     // Members
//     void createMappings(
//       const std::vector<std::vector<std::string>>& paths
//     );
//     void createFileSystemAdjList(
//       const std::vector<std::vector<std::string>>& paths
//     );
//   public:
//     std::vector<std::vector<std::string>> deleteDuplicateFolder(
//       std::vector<std::vector<std::string>>& paths
//     );
// };

// /**
//  * @brief Creates the idxToDirNameLookup and dirNameToIdxLookup mappings.
//  * 
//  * @algorithm
//  *  1.) Create the dirNameToIdxLookup
//  *  2.) Create the idxToDirNameLookup
//  * 
//  * @param paths - The paths that exist in the file system.
//  */
// void Solution::createMappings(
//   const std::vector<std::vector<std::string>>& paths
// ) {
//   static constexpr double EXPECTED_DIRNAME_UNIQUENESS_RATIO = (double)0.7;

//   size_t numDirApprox = 0;

//   for (const auto& path : paths)
//   {
//     numDirApprox += path.size();
//   }

//   numDirApprox = static_cast<size_t>(static_cast<double>(numDirApprox) * EXPECTED_DIRNAME_UNIQUENESS_RATIO);

//   this->dirNameToIdxLookup.reserve(numDirApprox);
//   this->idxToDirNameLookup.reserve(numDirApprox);

//   size_t nextIdx = 0;

//   for (const auto& path : paths)
//   {
//     for (const auto& dirName : path)
//     {
//       auto [_, inserted] = this->dirNameToIdxLookup.emplace(dirName, nextIdx);

//       if (inserted)
//       {
//         this->idxToDirNameLookup.emplace_back(dirName);
//         ++nextIdx;
//       }
//     }
//   }
// }

// /**
//  * @brief This creates the adjacency list that represents the file system.
//  * 
//  * @param paths - The paths that exist in the file system.
//  */
// void Solution::createFileSystemAdjList(
//   const std::vector<std::vector<std::string>>& paths
// ) {
//   const size_t numDirs = this->idxToDirNameLookup.size();
  
//   this->fileSystemAdjList.assign(numDirs, std::vector<size_t>{});

//   for (const auto& path : paths)
//   {
//     const size_t pathSize = path.size();

//     if (pathSize < 2zu)
//     {
//       continue;
//     }

//     size_t parentIdx = this->dirNameToIdxLookup.at(path.at(0));

//     for (size_t i = 1zu; i < pathSize; ++i)
//     {
//       const size_t childIdx = this->dirNameToIdxLookup.at(path.at(i));

//       this->fileSystemAdjList.at(parentIdx).push_back(childIdx);

//       parentIdx = childIdx;
//     }
//   }
// }

// /**
//  * @brief Algorithm that deletes duplicate directories.
//  * 
//  * @param paths - All dir paths in the system.
//  * @return std::vector<std::vector<std::string>> 
//  */
// std::vector<std::vector<std::string>> Solution::deleteDuplicateFolder(
//   std::vector<std::vector<std::string>>& paths
// ) {
//   this->createMappings(paths);
//   this->createFileSystemAdjList(paths);
//   return {};
// }









































































// /**
//  * @brief This is LeetCode #1948, Hard, "Delete Duplicate Folders in System."
//  * 
//  * @algorithm
//  *  1.) Build a tree using the given file system.
//  *  2.) Serialize each subtree in the tree using DFS algorithm.
//  *  3.) Hash each one of the subtrees and find duplicates.
//  *  4.) Kill the duplicates.
//  */
// class Solution {
//   private:
//     std::unordered_map<std::string, size_t> createDirToIdxMap(const std::vector<std::vector<std::string>>& paths);
//     std::vector<std::vector<size_t>> createAdjList(const std::vector<std::vector<std::string>>& paths, const std::unordered_map<std::string, size_t>& dirNameToIdxMap);
//   public:
//     std::vector<std::vector<std::string>> deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths);
// };

// /**
//  * @brief This creates a mapping between all of the directory names in the table to an index for simplicity.
//  * 
//  * @param paths This represents the tree structure in our system.
//  * @return std::unordered_map<std::string, int> 
//  */
// std::unordered_map<std::string, size_t> Solution::createDirToIdxMap(const std::vector<std::vector<std::string>>& paths) {

//   static constexpr double ESTIMATED_UNIQUENESS_RATIO = (double)0.7;

//   size_t numDirsApprox = 0; // This is going to represent an approximation for the number of directories that we are working with.
//   for (const auto& path : paths) {
//     numDirsApprox += path.size();
//   }
  
//   numDirsApprox = static_cast<size_t>(static_cast<double>(numDirsApprox) * ESTIMATED_UNIQUENESS_RATIO);

//   // Create and allocate space for our dir name to idx mapping.
//   std::unordered_map<std::string, size_t> dirNameToIdxMap;
//   dirNameToIdxMap.reserve(numDirsApprox);

//   size_t nextIdx = 0; // cur index

//   for (const auto& path : paths) {
//     for (const auto& dirName : path) {
//       auto [_, inserted] = dirNameToIdxMap.emplace(dirName, nextIdx);
//       if (inserted) {
//         ++nextIdx;
//       }
//     }
//   }

//   return dirNameToIdxMap;
// }

// /**
//  * @brief Create a adjacency list from the paths that we are given.
//  * 
//  * @param paths - Represents the paths that are in the system.
//  * @param dirNameToIdxMap - Represents the dir name to index mapping for efficiency.
//  * @return std::vector<std::vector<size_t>> 
//  */
// std::vector<std::vector<size_t>> Solution::createAdjList(const std::vector<std::vector<std::string>>& paths, const std::unordered_map<std::string, size_t>& dirNameToIdxMap) {
  
//   const size_t numDirNames = dirNameToIdxMap.size();

//   std::vector<std::vector<size_t>> adjList(numDirNames);

//   for (const auto& path : paths) {
//     if (path.size() < 2zu) {
//       continue;
//     }
//     size_t parentIdx = dirNameToIdxMap.at(path[0]);
//     for (size_t i = 1zu; i < path.size(); ++i) {
//       const size_t childIdx = dirNameToIdxMap.at(path[i]);
//       adjList[parentIdx].push_back(childIdx);
//       parentIdx = childIdx;
//     }
//   }

//   return adjList;
// }

// /**
//  * @brief Algorithm that deletes duplicate directories.
//  * 
//  * @param paths - All dir paths in the system.
//  * @return std::vector<std::vector<std::string>> 
//  */
// std::vector<std::vector<std::string>> Solution::deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths) {
//   auto dirNameToIdxMap = this->createDirToIdxMap(paths);
//   auto adjListGraph = this->createAdjList(paths, dirNameToIdxMap);
//   return {};
// }





































  /**
   * @brief This method discovers all of the folder names in the system paths. This is then used so that we can just store references to the 
   *        the folders rather than the std::strin for each reference.
   * 
   * @param paths - All dir paths in the system.
   * @return std::vector<std::string> 
   */
  // std::vector<std::string> discoverAllDirNames(const std::vector<std::vector<std::string>>& paths) {
  //   size_t sizeApprox = 0;
  //   for (const auto& path : paths)
  //     sizeApprox += path.size();
  //   static constexpr double ESTIMATED_UNIQUENESS_RATIO = 0.7; // this is a guess, can be changed.
  //   const size_t sizeReserve = static_cast<size_t>(sizeApprox * ESTIMATED_UNIQUENESS_RATIO);
  //   std::unordered_set<std::string> dirNameSet;
  //   dirNameSet.reserve(sizeReserve);
  //   for (const auto& path : paths)
  //     for (const auto& dirName : path)
  //       dirNameSet.emplace(dirName);
  //   std::vector<std::string> dirNameVec;
  //   dirNameVec.reserve(dirNameSet.size());
  //   for (auto&& dirName : dirNameSet)
  //     dirNameVec.emplace_back(std::move(dirName));
  //   return dirNameVec;
  // }
