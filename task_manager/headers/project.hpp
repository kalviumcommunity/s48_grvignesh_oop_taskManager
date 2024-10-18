// Problem Statement: Create a Car Class in C++
// Create a class named Car with the following specifications:

// 1. Private Data Members:
// id (int): A unique identifier for each car.
// model (string): The model name of the car.
// manufacturer (string): The manufacturer of the car.
// totalCars (static int): A static data member to track the number of Car objects created.
// 2. Public Member Functions:
// Constructor: Initializes the id, model, and manufacturer of the car and increments the totalCars counter.
// Destructor: Decrements the totalCars counter when a car object is deleted.
// Static Function: getTotalCars to return the total number of car objects created.
// Function: display to print the details of the car in the format:
// ID: <id>, Model: <model>, Manufacturer: <manufacturer>
// Additional Task:
// Create an array of 3 Car objects using dynamic memory allocation.
// Take input for each car’s id, model, and manufacturer from the command line.
// Display the details of all cars.
// Display the total number of cars created at the end.
// Example Input:
// Copy code
// 1
// Model S
// Tesla
// 2
// Mustang
// Ford
// 3
// Civic
// Honda
// Example Output:
// yaml
// Copy code
// Car 1: ID: 1, Model: Model S, Manufacturer: Tesla
// Car 2: ID: 2, Model: Mustang, Manufacturer: Ford
// Car 3: ID: 3, Model: Civic, Manufacturer: Honda
// Total Cars: 3

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int id;
    string model;
    string manufacturer;
    static int totalCars; // Static data member to track the total number of cars

public:
    // Constructor
    Car(int carId, string carModel, string carManufacturer)
    {
        id = carId;
        model = carModel;
        manufacturer = carManufacturer;
        totalCars++; // Increment total cars when a new object is created
    }

    // Destructor
    ~Car()
    {
        totalCars--; // Decrement total cars when an object is destroyed
    }

    // Static function to get total cars
    static int getTotalCars()
    {
        return totalCars;
    }

    // Function to display car details
    void display() const
    {
        cout << "ID: " << id << ", Model: " << model << ", Manufacturer: " << manufacturer << endl;
    }
};

// Initialize static member
int Car::totalCars = 0;

int main()
{
    const int numCars = 3;
    Car *cars[numCars]; // Array of pointers to Car objects

    // Take input for each car
    for (int i = 0; i < numCars; i++)
    {
        int id;
        string model, manufacturer;

        cout << "Enter details for car " << (i + 1) << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cin.ignore(); // Clear the input buffer
        cout << "Model: ";
        getline(cin, model);
        cout << "Manufacturer: ";
        getline(cin, manufacturer);

        cars[i] = new Car(id, model, manufacturer); // Dynamically allocate memory for Car
    }

    // Display the details of all cars
    for (int i = 0; i < numCars; i++)
    {
        cout << "Car " << (i + 1) << ": ";
        cars[i]->display();
    }

    // Display the total number of cars created
    cout << "Total Cars: " << Car::getTotalCars() << endl;

    // Deallocate memory
    for (int i = 0; i < numCars; i++)
    {
        delete cars[i]; // Free the dynamically allocated memory
    }

    return 0;
}
