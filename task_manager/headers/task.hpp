#ifndef TASK_HPP
#define TASK_HPP

#include <string>
using namespace std;

class Task
{
private:
    string title;
    bool priority;
    string description;
    static int taskCount;

public:
    Task(const string &taskTitle, bool taskPriority, const string &taskDescription);
    ~Task();

    void displayTask() const;

    static int getTaskCount();
};

#endif
