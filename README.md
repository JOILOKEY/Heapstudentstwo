# Heapstudentstwo 
Heap of Students part 2

This is a C++ program that reads a list of students from a CSV file and lets the user interact with that data through a menu. The student information includes things like name, address, date of birth, graduation date, and number of credits. The program uses multiple C++ files and object-oriented programming (OOP) to keep everything organized.

Main Goal of the Program The main goal is to help the user:

See a list of student names.

View full information about each student.

Search for students by last name.

Exit the program when finished.

How the Program is Built

The program is split into several files, each doing a specific job. This helps keep the code neat and easier to manage. Here’s how it’s structured:

Address class – This part is responsible for holding and displaying the student’s street, city, state, and ZIP code.

Date class – This class stores a month, day, and year. It’s used for things like birth dates and graduation dates.

Student class – This is the big one. It puts everything together (name, address, dates, and credits) and can display all of a student’s info.

main.cpp – This is where the action happens. It brings all the pieces together and interacts with the user.

Where does the data come from?

All the student data comes from a file named student.csv. The file stores all the students in one big list, with each student on a single line. The program reads each line and splits it into pieces like first name, last name, street address, etc.

Run the program

When the program starts, it automatically reads all the students from the file and stores them in memory.

Then, it shows a menu that lets you pick what you want to do.

If you choose to print all student names, it shows each student’s last name and first name.

If you choose to see all student data, it prints everything about every student.

If you choose to search, the program asks for a last name and shows anyone with a matching name.

If you choose to quit, the program deletes the student data from memory and exits.

How does it keep the program clean?

This program creates objects on the heap (meaning in memory), so it’s important to delete them when you're done. That’s why at the end, the program cleans up all the memory it used.

How is it built

It uses a Makefile, which is like a set of instructions to build and run the program with one simple command (make). This keeps everything easier than typing long commands each time.
