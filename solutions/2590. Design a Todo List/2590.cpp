struct Task {
  // int taskId;
  string taskDescription;
  int dueDate;
  unordered_set<string> tags;

  bool operator<(const Task& other) const {
    return dueDate < other.dueDate;
  }
};

class TodoList {
 public:
  int addTask(int userId, string taskDescription, int dueDate,
              vector<string> tags) {
    userIdToTaskIdToTasks[userId][++taskId] =
        Task{.taskDescription = taskDescription,
             .dueDate = dueDate,
             .tags = {begin(tags), end(tags)}};
    taskIds.insert(taskId);
    return taskId;
  }

  vector<string> getAllTasks(int userId) {
    vector<string> res;
    for (const Task& task : getTasksSortedByDueDate(userId))
      res.push_back(task.taskDescription);
    return res;
  }

  vector<string> getTasksForTag(int userId, string tag) {
    vector<string> res;
    for (const Task& task : getTasksSortedByDueDate(userId))
      if (task.tags.count(tag))
        res.push_back(task.taskDescription);
    return res;
  }

  void completeTask(int userId, int taskId) {
    if (!taskIds.count(taskId))
      return;
    const auto it = userIdToTaskIdToTasks.find(userId);
    if (it == cend(userIdToTaskIdToTasks))
      return;
    auto& taskIdToTasks = it->second;
    if (!taskIdToTasks.count(taskId))
      return;
    taskIdToTasks.erase(taskId);
  }

 private:
  int taskId = 0;
  unordered_set<int> taskIds;
  // {userId: {taskId: tasks}}
  unordered_map<int, unordered_map<int, Task>> userIdToTaskIdToTasks;

  vector<Task> getTasksSortedByDueDate(int userId) {
    const auto it = userIdToTaskIdToTasks.find(userId);
    if (it == cend(userIdToTaskIdToTasks))
      return {};
    set<Task> tasks;
    for (const auto& [_, task] : it->second)
      tasks.insert(task);
    return {begin(tasks), end(tasks)};
  }
};
