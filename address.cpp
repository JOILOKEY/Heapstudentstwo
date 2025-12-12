#include "address.h"
#include <iostream>

using namespace std;

void Address::init(string st, string c, string s, int z) {
    street = st;
    city = c;
    state = s;
    zip = z;
}


void Address::printAddress() const {
    cout << street << endl;
    cout << city << ", " << state << " " << zip << endl;
}
