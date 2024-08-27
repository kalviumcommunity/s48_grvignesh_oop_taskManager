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
        : title(taskTitle), priority(taskPriority), description(taskDescription) {}

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
        : name(projectName), type(projectType), deadline(projectDeadline), company(projectCompany) {}

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
    Task task1("Design UI", true, "Create mockups for the new user interface.");
    Task task2("Develop Backend", false, "Implement API endpoints and database connections.");

    Project project1("Website Redesign", "Development", "2024-12-31", "TechCorp");
    Project project2("API Development", "Research", "2024-10-15", "InnovaTech");

    task1.displayTask();
    cout << endl;
    task2.displayTask();

    cout << endl;
    project1.displayProject();
    cout << endl;
    project2.displayProject();

    return 0;
}
