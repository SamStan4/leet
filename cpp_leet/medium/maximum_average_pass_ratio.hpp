#include <vector>
#include <queue>
#include <cassert>
#include <ios>
#include <iostream>

class Solution {
  private:
    struct classExamStat {
      private:
        int numberOfStudents;
        int numberOfPasses;
      public:
        classExamStat(const std::vector<int>& vec);
        double getRatio() const;
        double getPotentialRatio() const;
        double getPotentialImprovement() const;
        void addSmartStudent();
        bool operator<(const classExamStat& other) const;
    };
  public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents);
};

Solution::classExamStat::classExamStat(const std::vector<int>& vec) {
  this->numberOfStudents = vec.at(1);
  this->numberOfPasses = vec.at(0);
}

double Solution::classExamStat::getRatio() const {
  return static_cast<double>(this->numberOfPasses) / static_cast<double>(this->numberOfStudents);
}

double Solution::classExamStat::getPotentialRatio() const {
  return (static_cast<double>(this->numberOfPasses) + 1) / (static_cast<double>(this->numberOfStudents) + 1);
}

double Solution::classExamStat::getPotentialImprovement() const {
  return this->getPotentialRatio() - this->getRatio();
}

void Solution::classExamStat::addSmartStudent() {
  ++this->numberOfStudents;
  ++this->numberOfPasses;
}

bool Solution::classExamStat::operator<(const classExamStat& other) const {
  return this->getPotentialImprovement() < other.getPotentialImprovement();
}

double Solution::maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
  std::priority_queue<classExamStat> pq(classes.begin(), classes.end());
  for (int i = 0; i < extraStudents; ++i) {
    auto examClass = pq.top();
    pq.pop();
    examClass.addSmartStudent();
    pq.push(examClass);
  }
  double avgTotal = 0;
  while (!pq.empty()) {
    avgTotal += pq.top().getRatio();
    pq.pop();
  }
  return avgTotal / static_cast<double>(classes.size());
}

static int fastIo = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();