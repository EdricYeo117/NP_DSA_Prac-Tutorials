#include "Person.h"

// Constructor implementation
Person::Person(const string& name, const string& telNo) : name(name), telNo(telNo) {}

// Getters implementation
string Person::getName() const {
    return name;
}

string Person::getTelNo() const {
    return telNo;
}