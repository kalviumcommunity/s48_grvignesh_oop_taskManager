#include "task.hpp"

int Task::taskCount = 0;

// Default constructor
Task::Task()
    : title("Untitled Task"), priority(false), description("No description provided")
{
    taskCount++;
    cout << "Default constructor called. Task created." << endl;
}

// Parameterized constructor
Task::Task(const string &taskTitle, bool taskPriority, const string &taskDescription)
    : priority(taskPriority), description(taskDescription)
{
    if (isTitleValid(taskTitle))
    {
        title = taskTitle;
    }
    else
    {
        title = "Untitled Task"; // Default title if invalid input
    }

    taskCount++;
    cout << "Parameterized constructor called. Task created with title: " << title << endl;
}

// Destructor
Task::~Task()
{
    taskCount--;
    cout << "Destructor called. Task destroyed." << endl;
}

// Display task details
void Task::displayTask() const
{
    cout << "Task Title: " << title << endl;
    cout << "Priority: " << (priority ? "High" : "Low") << endl;
    cout << "Description: " << description << endl;
}

// Static method to get task count
int Task::getTaskCount()
{
    return taskCount;
}

// Private method to validate title
bool Task::isTitleValid(const string &taskTitle) const
{
    return !taskTitle.empty();
}
