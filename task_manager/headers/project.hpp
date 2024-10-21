#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>
#include <iostream>
using namespace std;

class Project
{
private:
    string name;
    string type;
    string deadline;
    string company;
    static int projectCount; // private static member

public:
    // Default constructor
    Project() : name("Unnamed"), type("Unknown"), deadline("No deadline"), company("Unknown")
    {
        projectCount++;
    }

    // Parameterized constructor
    Project(const string &projectName, const string &projectType, const string &projectDeadline, const string &projectCompany)
        : name(projectName), type(projectType), deadline(projectDeadline), company(projectCompany)
    {
        projectCount++;
    }

    // Destructor
    ~Project()
    {
        projectCount--;
    }

    void displayProject() const
    {
        cout << "Project Name: " << name << endl;
        cout << "Project Type: " << type << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Company: " << company << endl;
    }

    // Getter function for project count
    static int getProjectCount()
    {
        return projectCount;
    }
};

// Initialize static member
int Project::projectCount = 0;

#endif
