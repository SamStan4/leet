#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <ios>

class TaskItem {

  private:

    int taskId;

    int taskPriority;

    int userId;

  public:

  TaskItem(void)
    :userId(0), taskId(0), taskPriority(0) {}

  TaskItem(const int newUserId, const int newTaskId, const int newTaskPriority)
    : userId(newUserId), taskId(newTaskId), taskPriority(newTaskPriority) {}

  TaskItem(const TaskItem& other)
    : taskId(other.taskId), taskPriority(other.taskPriority), userId(other.userId) {}

  ~TaskItem() = default;

  int getTaskId(void) const { return this->taskId; }

  int getTaskPriority(void) const { return this->taskPriority; }

  int getUserId(void) const { return this->userId; }

  void setTaskPriority(const int newTaskPriority) { this->taskPriority = newTaskPriority; }

  TaskItem& operator=(const TaskItem& other) {
    if (this != &other) {
      this->taskId = other.taskId;
      this->taskPriority = other.taskPriority;
      this->userId = other.userId;
    }
    return *this;
  }

  bool operator<(const TaskItem& other) const {
    if (this->taskPriority != other.taskPriority) {
      return this->taskPriority < other.taskPriority;
    }
    return this->taskId < other.taskId;
  }
};

class TaskManager {

  private:

    int numTasks;
    std::set<TaskItem> taskStore;
    std::unordered_map<int, TaskItem> taskIdToTaskItem;

    void add(const TaskItem& newItem) {
      this->taskStore.insert(newItem);
      this->taskIdToTaskItem.insert_or_assign(newItem.getTaskId(), *(this->taskStore.find(newItem)));
      ++this->numTasks;
    }

    void rmv(const TaskItem& item) {
      this->taskIdToTaskItem.erase(item.getTaskId());
      this->taskStore.erase(item);
      --this->numTasks;
    }

  public:

    TaskManager(const std::vector<std::vector<int>>& tasks) {
      this->numTasks = 0;
      const int n = static_cast<int>(tasks.size());
      for (int i = 0; i < n; ++i) {
        this->add(tasks[i][0], tasks[i][1], tasks[i][2]);
      }
    }
    
    void add(const int userId, const int taskId, const int priority) {
      TaskItem item(userId, taskId, priority);
      this->add(item);
    }
    
    void edit(int taskId, int newPriority) {
      TaskItem item = this->taskIdToTaskItem[taskId];
      this->rmv(item);
      item.setTaskPriority(newPriority);
      this->add(item);
    }
    
    void rmv(int taskId) {
      TaskItem item = this->taskIdToTaskItem[taskId];
      this->rmv(item);
    }
    
    int execTop() {
      if (this->numTasks <= 0) {
        return -1;
      }
      TaskItem topItem = *(this->taskStore.rbegin());
      this->rmv(topItem);
      return topItem.getUserId();
    }
};

static int init = []() {
  std::ios_base::sync_with_stdio(false),
    std::cin.tie(nullptr),
    std::cout.tie(nullptr);
  return 0;
} ();