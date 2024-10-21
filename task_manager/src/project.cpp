#include "project.hpp"
#include <iostream>

// Initialize static member
int Project::projectCount = 0;

Project::Project(const string &projectName, const string &projectType, const string &projectDeadline, const string &projectCompany)
    : name(projectName), type(projectType), deadline(projectDeadline), company(projectCompany)
{
    projectCount++;
}

Project::~Project()
{
    projectCount--; // Decrease project count when project is destroyed
}

void Project::displayProject() const
{
    cout << "Project Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Deadline: " << deadline << endl;
    cout << "Company: " << company << endl;
}

// Static function to get project count
int Project::getProjectCount()
{
    return projectCount;
}
