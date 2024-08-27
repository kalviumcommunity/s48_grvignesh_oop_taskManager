#include <iostream>
#include <string>

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
    Task tasks[] = {
        Task("Design UI", true, "Create mockups for the new user interface."),
        Task("Develop Backend", false, "Implement API endpoints and database connections.")};

    Project projects[] = {
        Project("Website Redesign", "Development", "2024-12-31", "TechCorp"),
        Project("API Development", "Research", "2024-10-15", "InnovaTech")};

    for (const auto &task : tasks)
    {
        task.displayTask();
        cout << endl;
    }

    for (const auto &project : projects)
    {
        project.displayProject();
        cout << endl;
    }

    return 0;
}
