#include <iostream>
#include <string>

class Task {
public:
    Task(const std::string& title, const std::string& description)
        : title_(title), description_(description), isCompleted_(false) {}

    const std::string& getTitle() const {
        return title_;
    }

    const std::string& getDescription() const {
        return description_;
    }

    bool isCompleted() const {
        return isCompleted_;
    }

    void markAsCompleted() {
        isCompleted_ = true;
    }

private:
    std::string title_;
    std::string description_;
    bool isCompleted_;
};

class Project : public Task {
public:
    Project(const std::string& title, const std::string& description, const std::string& deadline, const std::string& company)
        : Task(title, description), deadline_(deadline), company_(company) {}

    const std::string& getDeadline() const {
        return deadline_;
    }

    const std::string& getCompany() const {
        return company_;
    }

private:
    std::string deadline_;
    std::string company_;
};

class Milestone : public Task, public Project {
public:
    Milestone(const std::string& title, const std::string& description, const std::string& deadline, const std::string& company)
        : Task(title, description), Project(title, description, deadline, company) {}
};

int main() {
    // Create a Task
    Task task("Task 1", "Description 1");
    std::cout << "Task Title: " << task.getTitle() << std::endl;
    std::cout << "Task Description: " << task.getDescription() << std::endl;

    // Create a Project
    Project project("Project 1", "Project Description", "2023-12-31", "Company A");
    std::cout << "Project Title: " << project.getTitle() << std::endl;
    std::cout << "Project Description: " << project.getDescription() << std::endl;
    std::cout << "Project Deadline: " << project.getDeadline() << std::endl;
    std::cout << "Project Company: " << project.getCompany() << std::endl;

    // Create a Milestone
    Milestone milestone("Milestone 1", "Milestone Description", "2023-11-30", "Company A");
    std::cout << "Milestone Title: " << milestone.getTitle() << std::endl;
    std::cout << "Milestone Description: " << milestone.getDescription() << std::endl;
    std::cout << "Milestone Deadline: " << milestone.getDeadline() << std::endl;
    std::cout << "Milestone Company: " << milestone.getCompany() << std::endl;

    return 0;
}