#ifndef STUDENT_H
#define STUDENT_H

#include "address.h"
#include "date.h"
#include <string>
using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    Address address;
    Date birthDate;
    Date gradDate;
    int creditHours;

public:
    Student(string fName, string lName, Address addr, Date dob, Date grad, int credits);
    void printStudent() const;
    string getFullName() const;
    string getLastName() const;
    string getFirstName() const;  
    int getCreditHours() const;
};

#endif

