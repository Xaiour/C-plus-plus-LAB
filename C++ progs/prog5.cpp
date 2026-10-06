#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    double basicSalary;
    double hra;
    double da;
    double totalSalary;

public:
    // Default Constructor
    Person() {
        strcpy(name, "");
        age = 0;
        strcpy(address, "");
        basicSalary = 0.0;
        hra = 0.0;
        da = 0.0;
        totalSalary = 0.0;
    }

    // Parameterized Constructor to initialize person details and calculate salary slip
    Person(const char* pName, int pAge, const char* pAddress, double basic) {
        strcpy(name, pName);
        age = pAge;
        strcpy(address, pAddress);
        basicSalary = basic;
        
        // Calculating salary components (e.g., HRA = 20% of basic, DA = 50% of basic)
        hra = 0.20 * basicSalary;
        da = 0.50 * basicSalary;
        totalSalary = basicSalary + hra + da;
    }

    // Member function to input details
    void inputData() {
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 64);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 64);
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        // Calculate components
        hra = 0.20 * basicSalary;
        da = 0.50 * basicSalary;
        totalSalary = basicSalary + hra + da;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Function to display salary slip
    void displaySalarySlip() const {
        cout << "\n-----------------------------\n";
        cout << "        SALARY SLIP          \n";
        cout << "-----------------------------\n";
        cout << "Name:    " << name << "\n";
        cout << "Age:     " << age << "\n";
        cout << "Address: " << address << "\n";
        cout << "-----------------------------\n";
        cout << "Basic Salary : " << basicSalary << "\n";
        cout << "HRA (20%)    : " << hra << "\n";
        cout << "DA (50%)     : " << da << "\n";
        cout << "-----------------------------\n";
        cout << "Total Salary : " << totalSalary << "\n";
        cout << "-----------------------------\n";
    }
};

// Inline function to obtain the youngest and eldest age from an array of Person objects
inline void findYoungestAndEldest(const Person p[], int size) {
    if (size <= 0) return;

    int youngest = p[0].getAge();
    int eldest = p[0].getAge();

    for (int i = 1; i < size; ++i) {
        int currentAge = p[i].getAge();
        if (currentAge < youngest) {
            youngest = currentAge;
        }
        if (currentAge > eldest) {
            eldest = currentAge;
        }
    }

    cout << "\n--- Age Statistics ---\n";
    cout << "Youngest Age: " << youngest << "\n";
    cout << "Eldest Age: " << eldest << "\n";
}

int main() {
    // Array of objects of class Person of size 10
    const int SIZE = 10; // Reduced to 2 for easier testing, can be changed to 10 as per question
    Person persons[SIZE];

    cout << "Enter details for " << SIZE << " persons:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "\nPerson " << (i + 1) << ":\n";
        persons[i].inputData();
    }

    // (a) Using the inline function to find youngest and eldest age
    findYoungestAndEldest(persons, SIZE);

    // (b) Displaying the salary slip for each person using constructors/methods
    cout << "\n--- Generating Salary Slips for all persons ---\n";
    for (int i = 0; i < SIZE; ++i) {
        persons[i].displaySalarySlip();
    }

    return 0;
}
