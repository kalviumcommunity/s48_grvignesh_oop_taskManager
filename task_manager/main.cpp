#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string& title, const string& description) : title_(title), description_(description), isCompleted_(false) {}

    const string& getTitle() const { return title_; }
    const string& getDescription() const { return description_; }
    bool isCompleted() const { return isCompleted_; }
    void markAsCompleted() { isCompleted_ = true; }

private:
    string title_;
    string description_;
    bool isCompleted_;
};

class Project : public Task {
public:
    Project(const string& title, const string& description, const string& deadline, const string& company) 
        : Task(title, description), deadline_(deadline), company_(company) {}

    const string& getDeadline() const { return deadline_; }
    const string& getCompany() const { return company_; }

private:
    string deadline_;
    string company_;
};

class Milestone : public Task {
public:
    Milestone(const string& title, const string& description, const string& deadline, const string& company) 
        : Task(title, description), deadline_(deadline), company_(company) {}

    const string& getDeadline() const { return deadline_; }
    const string& getCompany() const { return company_; }

private:
    string deadline_;
    string company_;
};

class TaskList {
public:
    void addTask(Task* task) { tasks_.push_back(task); }

    void printTasks() {
        for (Task* task : tasks_) {
            cout << "Title: " << task->getTitle() << endl;
            cout << "Description: " << task->getDescription() << endl;

            if (auto* project = dynamic_cast<Project*>(task)) {
                cout << "Deadline: " << project->getDeadline() << endl;
                cout << "Company: " << project->getCompany() << endl;
            } else if (auto* milestone = dynamic_cast<Milestone*>(task)) {
                cout << "Deadline: " << milestone->getDeadline() << endl;
                cout << "Company: " << milestone->getCompany() << endl;
            }

            cout << endl;
        }
    }

private:
    vector<Task*> tasks_;
};

int main() {
    TaskList taskList;
    taskList.addTask(new Task("Task 1", "Description 1"));
    taskList.addTask(new Project("Project 1", "Project Description", "2023-12-31", "Company A"));
    taskList.addTask(new Milestone("Milestone 1", "Milestone Description", "2023-11-30", "Company A"));

    taskList.printTasks();

    // Delete dynamically allocated objects
    for (Task* task : taskList.tasks_) {
        delete task;
    }

    return 0;
}