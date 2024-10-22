#include "module.h"

// Constructor implementation
Module::Module(const std::string &name, double ca, double ct, double asg)
    : name(name), ca(ca), ct(ct), asg(asg) {}

// Setters implementation
void Module::setName(const std::string &name) { this->name = name; }
void Module::setCa(double ca) { this->ca = ca; }
void Module::setCt(double ct) { this->ct = ct; }
void Module::setAsg(double asg) { this->asg = asg; }

// Getters implementation
std::string Module::getName() const { return name; }
double Module::getCa() const { return ca; }
double Module::getCt() const { return ct; }
double Module::getAsg() const { return asg; }

// Calculate total score implementation
double Module::calculateTotal() const
{
    return (ca * 0.3) + (ct * 0.3) + (asg * 0.4);
}
