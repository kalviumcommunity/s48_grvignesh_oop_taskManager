#include "task.hpp"
#include <iostream>

using namespace std;

// Initialize static member
int Task::taskCount = 0;

// Constructor implementation
Task::Task(const string &taskTitle, bool taskPriority, const string &taskDescription)
    : priority(taskPriority), description(taskDescription)
{
    // Use the validation method to set the title
    if (isTitleValid(taskTitle))
    {
        title = taskTitle;
    }
    else
    {
        title = "Untitled Task"; // Default title for invalid input
    }

    // Increment task count when a task is created
    taskCount++;
}

// Destructor implementation
Task::~Task()
{
    // Decrement task count when a task is destroyed
    taskCount--;
}

// Display task details
void Task::displayTask() const
{
    cout << "Task Title: " << title << endl;
    cout << "Priority: " << (priority ? "High" : "Low") << endl;
    cout << "Description: " << description << endl;
}

// Static method to get the current task count
int Task::getTaskCount()
{
    return taskCount;
}

// Private method to validate the task title
bool Task::isTitleValid(const string &taskTitle) const
{
    return !taskTitle.empty();
}
