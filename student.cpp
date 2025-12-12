#include "student.h"
#include <iostream>

using namespace std;

Student::Student(string fName, string lName, Address addr, Date dob, Date grad, int credits)
    : firstName(fName), lastName(lName), address(addr), birthDate(dob), gradDate(grad), creditHours(credits) {}

void Student::printStudent() const {
    cout << firstName << " " << lastName << endl;
    address.printAddress();
    cout << "DOB: ";
    birthDate.printDate();
    cout << "Grad: ";
    gradDate.printDate();
    cout << "Credits: " << creditHours << endl;
    cout << "____________________________________" << endl;
}

string Student::getFullName() const {
    return lastName + ", " + firstName;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

int Student::getCreditHours() const {
    return creditHours;
}
