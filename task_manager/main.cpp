#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task
{
public:
    string title;
    bool priority;
    string description;

    static int taskCount;

    Task(const string &taskTitle, bool taskPriority, const string &taskDescription)
    {
        this->title = taskTitle;
        this->priority = taskPriority;
        this->description = taskDescription;
        taskCount++;
    }

    void displayTask() const
    {
        cout << "Task Title: " << title << endl;
        cout << "Priority: " << (priority ? "High" : "Low") << endl;
        cout << "Description: " << description << endl;
    }

    static int getTaskCount() // Static member function
    {
        return taskCount;
    }
};

// Initialize static variable
int Task::taskCount = 0;

class Project
{
public:
    string name;
    string type;
    string deadline;
    string company;

    static int projectCount;

    Project(const string &projectName, const string &projectType, const string &projectDeadline, const string &projectCompany)
    {
        this->name = projectName;
        this->type = projectType;
        this->deadline = projectDeadline;
        this->company = projectCompany;
        projectCount++;
    }

    void displayProject() const
    {
        cout << "Project Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Company: " << company << endl;
    }

    static int getProjectCount()
    {
        return projectCount;
    }
};

// Initialize static variable
int Project::projectCount = 0;

int main()
{
    Task *task1 = new Task("Design UI", true, "Create mockups for the new user interface.");
    Task *task2 = new Task("Develop Backend", false, "Implement API endpoints and database connections.");

    vector<Task *> tasks = {task1, task2};

    Project *project1 = new Project("Website Redesign", "Development", "2024-12-31", "TechCorp");
    Project *project2 = new Project("API Development", "Research", "2024-10-15", "InnovaTech");

    vector<Project *> projects = {project1, project2};

    for (const auto &task : tasks)
    {
        task->displayTask();
        cout << endl;
    }

    for (const auto &project : projects)
    {
        project->displayProject();
        cout << endl;
    }

    // Use the static member function
    cout << "Total Tasks: " << Task::getTaskCount() << endl;
    cout << "Total Projects: " << Project::getProjectCount() << endl;

    for (auto task : tasks)
    {
        delete task;
    }
    for (auto project : projects)
    {
        delete project;
    }

    return 0;
}
