#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string& title, const string& description) : title_(title), description_(description) {}

    virtual ~Task() = default; // Virtual destructor for proper polymorphic behavior

    const string& getTitle() const { return title_; }
    const string& getDescription() const { return description_; }

    virtual void printDetails() const = 0; // Pure virtual function

protected:
    string title_;
    string description_;
};

class Project : public Task {
public:
    Project(const string& title, const string& description, const string& deadline, const string& company) 
        : Task(title, description), deadline_(deadline), company_(company) {}

    void printDetails() const override {
        cout << "Title: " << getTitle() << endl;
        cout << "Description: " << getDescription() << endl;
        cout << "Deadline: " << deadline_ << endl;
        cout << "Company: " << company_ << endl;
    }

private:
    string deadline_;
    string company_;
};

class Milestone : public Task {
public:
    Milestone(const string& title, const string& description, const string& dueDate) 
        : Task(title, description), dueDate_(dueDate) {}

    void printDetails() const override {
        cout << "Title: " << getTitle() << endl;
        cout << "Description: " << getDescription() << endl;
        cout << "Due Date: " << dueDate_ << endl;
    }

private:
    string dueDate_;
};

class TaskList {
public:
    void addTask(Task* task) { tasks_.push_back(task); }

    void printTasks() {
        for (Task* task : tasks_) {
            task->printDetails();
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
    taskList.addTask(new Milestone("Milestone 1", "Milestone Description", "2023-11-30"));

    taskList.printTasks();

    // Delete dynamically allocated objects
    for (Task* task : taskList.tasks_) {
        delete task;
    }

    return 0;
}