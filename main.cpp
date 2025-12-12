#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm> 
#include "student.h"
#include "address.h"
#include "date.h"

using namespace std;

void loadStudents(vector<Student*>& students);
void showStudentNames(const vector<Student*>& students);
void printStudents(const vector<Student*>& students);
void findStudent(const vector<Student*>& students);
void deleteStudents(vector<Student*>& students);
string menu();

int main() {
    vector<Student*> students;
    loadStudents(students);  

    string choice = "";
    while (choice != "0") {
        choice = menu();

        if (choice == "1") {
            showStudentNames(students);
        } else if (choice == "2") {
            printStudents(students);
        } else if (choice == "3") {
            findStudent(students);
        } 
       
       	// Extra Credit Sorting
        else if (choice == "4") {  
            sort(students.begin(), students.end(),
                 [](Student* a, Student* b){ return a->getLastName() < b->getLastName(); });
            cout << "\nStudents sorted by last name:\n";
            showStudentNames(students);
        }
        else if (choice == "5") {  
            sort(students.begin(), students.end(),
                 [](Student* a, Student* b){ return a->getFirstName() < b->getFirstName(); });
            cout << "\nStudents sorted by first name:\n";
            showStudentNames(students);
        }
        else if (choice == "6") {  
            sort(students.begin(), students.end(),
                 [](Student* a, Student* b){ return a->getCreditHours() > b->getCreditHours(); });
            cout << "\nStudents sorted by credit hours (high to low):\n";
            showStudentNames(students);
        }
    }

    deleteStudents(students);
    return 0;
}

void loadStudents(vector<Student*>& students) {
    ifstream file("student.csv");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue; 
        stringstream ss(line);
        string fName, lName, street, city, state, zipStr, dobStr, gradStr, creditsStr;

        getline(ss, fName, ',');
        getline(ss, lName, ',');
        getline(ss, street, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zipStr, ',');
        getline(ss, dobStr, ',');
        getline(ss, gradStr, ',');
        getline(ss, creditsStr, ',');

        int zip = stoi(zipStr);
        int credits = stoi(creditsStr);

        Address addr;
        addr.init(street, city, state, zip);

        Date dob;
        dob.init(dobStr);

        Date grad;
        grad.init(gradStr);

        Student* s = new Student(fName, lName, addr, dob, grad, credits);
        students.push_back(s);
    }

    file.close();
}

void showStudentNames(const vector<Student*>& students) {
    for (Student* s : students) {
        cout << s->getFullName() << endl;
    }
}

void printStudents(const vector<Student*>& students) {
    for (Student* s : students) {
        s->printStudent();
    }
}

void findStudent(const vector<Student*>& students) {
    cout << "Last name of student: ";
    string target;
    getline(cin, target);

    bool found = false;
    for (Student* s : students) {
        if (s->getLastName().find(target) != string::npos) {
            s->printStudent();
            found = true;
        }
    }

    if (!found) {
        cout << "No students found with last name containing '" << target << "'." << endl;
    }
}

void deleteStudents(vector<Student*>& students) {
    for (Student* s : students) {
        delete s;
    }
    students.clear();
}

string menu() {
    cout << endl;
    cout << "0) quit" << endl;
    cout << "1) print all student names" << endl;
    cout << "2) print all student data" << endl;
    cout << "3) find a student" << endl;
    cout << "4) sort by last name" << endl;
    cout << "5) sort by first name" << endl;
    cout << "6) sort by credit hours" << endl;
    cout << "\nPlease choose 0-6: ";

    string choice;
    getline(cin, choice);
    return choice;
}
 
