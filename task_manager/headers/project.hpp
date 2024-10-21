#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>
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
    Project(const string &projectName, const string &projectType, const string &projectDeadline, const string &projectCompany);
    ~Project();

    void displayProject() const;

    // Getter functions for project count
    static int getProjectCount();
};

#endif // PROJECT_HPP
