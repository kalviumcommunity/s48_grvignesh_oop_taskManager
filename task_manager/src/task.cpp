#include "task.hpp"
#include <iostream>

int Task::taskCount = 0;

Task::Task(const string &taskTitle, bool taskPriority, const string &taskDescription)
    : priority(taskPriority), description(taskDescription)
{
    if (isValidTitle(taskTitle))
    {
        title = taskTitle;
        taskCount++;
    }
    else
    {
        title = "Untitled Task"; // Default title
        taskCount++;
    }
}

Task::~Task()
{
    taskCount--;
}

void Task::displayTask() const
{
    cout << "Task Title: " << title << endl;
    cout << "Priority: " << (priority ? "High" : "Low") << endl;
    cout << "Description: " << description << endl;
}

int Task::getTaskCount()
{
    return taskCount;
}

bool Task::isValidTitle(const string &taskTitle) const
{
    return !taskTitle.empty();
}
