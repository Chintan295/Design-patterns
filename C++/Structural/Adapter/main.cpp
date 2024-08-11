#include <iostream>
#include <string>

// Target interface
class Person {
public:
    virtual std::string getName() = 0;
};

// Adaptee interface
class Student {
public:
    std::string getFullName() {
        return "John Doe";
    }
};

// Adapter
class StudentAdapter : public Person {
private:
    Student* student;
public:
    StudentAdapter(Student* s) : student(s) {}
    std::string getName() override {
        return student->getFullName();
    }
};

int main() {
    // Create a Student object
    Student* student = new Student();

    // Create a StudentAdapter object
    Person* adapter = new StudentAdapter(student);

    // Use the adapter to call the getName() method
    std::cout << "Name: " << adapter->getName() << std::endl;

    // Clean up memory
    delete student;
    delete adapter;

    return 0;
}