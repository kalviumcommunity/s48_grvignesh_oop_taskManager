#include "../headers/task.hpp"
#include "../headers/project.hpp"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    // Create Task objects
    Task *task1 = new Task("Design UI", true, "Create mockups for the new user interface.");
    Task *task2 = new Task("Develop Backend", false, "Implement API endpoints and database connections.");
    vector<Task *> tasks = {task1, task2};

    // Create Project objects
    Project *project1 = new Project("Website Redesign", "Development", "2024-12-31", "TechCorp");
    Project *project2 = new Project("API Development", "Research", "2024-10-15", "InnovaTech");
    vector<Project *> projects = {project1, project2};

    // Display tasks and projects
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

    // Show totals
    cout << "Total Tasks: " << Task::getTaskCount() << endl;
    cout << "Total Projects: " << Project::getProjectCount() << endl;

    // Free allocated memory
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
