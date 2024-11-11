#ifndef MODULE_H // Include guard to prevent multiple inclusions
#define MODULE_H

using namespace std;
#include <string>

class Module
{
private:
    string name;
    double ca;
    double ct;
    double asg;

public:
    // Constructor
    Module(const string &name, double ca, double ct, double asg);

    // Setters
    void setName(const string &name);
    void setCa(double ca);
    void setCt(double ct);
    void setAsg(double asg);

    // Getters
    std::string getName() const;
    double getCa() const;
    double getCt() const;
    double getAsg() const;

    // Calculate total score with weights: ca: 30%, ct: 30%, asg: 40%
    double calculateTotal() const;
};
#include "Module.cpp"
#endif // MODULE_H
