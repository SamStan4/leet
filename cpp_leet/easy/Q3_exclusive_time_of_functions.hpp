#include <vector>
#include <string>
#include <stack>
#include <tuple>

class Solution {
  private:
    static std::tuple<int, std::string, int> parseLog(
      const std::string& logStr) noexcept;
  public:
    std::vector<int> exclusiveTime(
      int n,
      std::vector<std::string>& logs) noexcept;
};

std::tuple<int, std::string, int> Solution::parseLog(
  const std::string& logStr) noexcept {
  const size_t logStrSize = logStr.size();
  std::string buffer;
  int funcId = 0;
  std::string type;
  int timeStamp = 0;
  for (size_t i = 0, j = 0; i <= logStrSize; ++i) {
    if (logStrSize == i || ':' == logStr[i]) {
      switch (j) {
        case 0: funcId    = std::stoi(buffer); break;
        case 1: type      = buffer;            break;
        case 2: timeStamp = std::stoi(buffer); break;
      }
      buffer = "";
      ++j;
    } else {
      buffer.push_back(logStr[i]);
    }
  }
  return std::make_tuple(funcId, type, timeStamp);
}

std::vector<int> Solution::exclusiveTime(
  int n,
  std::vector<std::string>& logs) noexcept {
  std::vector<int> times(n, 0);
  std::stack<int> callStack;
  int prevTime = 0;
  for (const std::string& log : logs) {
    const auto [funcId, type, timeStamp] = Solution::parseLog(log);
    if (type == "start") {
      if (!callStack.empty()) {
        times[callStack.top()] += timeStamp - prevTime;
      }
      callStack.push(funcId);
      prevTime = timeStamp;
    } else { // end
      times[callStack.top()] += timeStamp - prevTime + 1;
      callStack.pop();
      prevTime = timeStamp + 1;
    }
  }
  return times;
}