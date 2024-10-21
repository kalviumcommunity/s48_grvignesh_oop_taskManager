#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <iostream>
using namespace std;

class Task
{
private:
    string title;
    bool priority;
    string description;
    static int taskCount;

    bool isTitleValid(const string &taskTitle) const;

public:
    // Default constructor
    Task();

    // Parameterized constructor
    Task(const string &taskTitle, bool taskPriority, const string &taskDescription);

    // Destructor
    ~Task();

    // Display task details
    void displayTask() const;

    // Static method to get the task count
    static int getTaskCount();
};

#endif
