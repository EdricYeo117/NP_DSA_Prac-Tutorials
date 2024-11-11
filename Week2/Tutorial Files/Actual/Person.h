#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    string telNo;

public:
    Person() = default;  // Default constructor
    Person(const string& name, const string& telNo);  // Parameterized constructor

    string getName() const;
    string getTelNo() const;
};
#include "Person.cpp"
#endif  // PERSON_H
