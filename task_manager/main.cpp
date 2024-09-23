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

    Task(const string &taskTitle, bool taskPriority, const string &taskDescription)
    {
        this->title = taskTitle;
        this->priority = taskPriority;
        this->description = taskDescription;
    }

    void displayTask() const
    {
        cout << "Task Title: " << title << endl;
        cout << "Priority: " << (priority ? "High" : "Low") << endl;
        cout << "Description: " << description << endl;
    }
};

class Project
{
public:
    string name;
    string type;
    string deadline;
    string company;

    Project(const string &projectName, const string &projectType, const string &projectDeadline, const string &projectCompany)
    {
        this->name = projectName;
        this->type = projectType;
        this->deadline = projectDeadline;
        this->company = projectCompany;
    }

    void displayProject() const
    {
        cout << "Project Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Company: " << company << endl;
    }
};

int main()
{
    // Dynamically allocate tasks
    Task *task1 = new Task("Design UI", true, "Create mockups for the new user interface.");
    Task *task2 = new Task("Develop Backend", false, "Implement API endpoints and database connections.");

    // Store tasks in a vector for easier management
    vector<Task *> tasks = {task1, task2};

    // Dynamically allocate projects
    Project *project1 = new Project("Website Redesign", "Development", "2024-12-31", "TechCorp");
    Project *project2 = new Project("API Development", "Research", "2024-10-15", "InnovaTech");

    // Store projects in a vector
    vector<Project *> projects = {project1, project2};

    // Display tasks
    for (const auto &task : tasks)
    {
        task->displayTask();
        cout << endl;
    }

    // Display projects
    for (const auto &project : projects)
    {
        project->displayProject();
        cout << endl;
    }

    // Clean up allocated memory
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
