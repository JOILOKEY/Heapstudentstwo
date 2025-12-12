#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address {
private:
    string street;
    string city;
    string state;
    int zip;

public:
    void init(string st, string c, string s, int z);
    void printAddress() const;
};

#endif
