#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    void init(string mmddyyyy);  
    void printDate() const;
};

#endif
