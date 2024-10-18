#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Person class based on the class diagram
class Person
{
private:
    string name;
    string telNo;

public:
    // Constructor
    Person(const string &name, const string &telNo)
    {
        this->name = name;
        this->telNo = telNo;
    }

    // Setters
    void setName(const string &name)
    {
        this->name = name;
    }

    void setTelNo(const string &telNo)
    {
        this->telNo = telNo;
    }

    // Getters
    string getName() const
    {
        return name;
    }

    string getTelNo() const
    {
        return telNo;
    }
};

class Module
{
private:
    string name;
    double ca;
    double ct;
    double asg;

public:
    Module(const string name, double ca, double ct, double asg)
    {
        this->name = name;
        this->ca = ca;
        this->ct = ct;
        this->asg = asg;
    }

    // Setters
    void setName(string name) { this->name = name; }
    void setCa(double ca) { this->ca = ca; }
    void setCt(double ct) { this->ct = ct; }
    void setAsg(double asg) { this->asg = asg; }

    // Getters
    string getName() const { return name; }
    double getCa() const { return ca; }
    double getCt() const { return ct; }
    double getAsg() const { return asg; }

    // Calculate total score with weights: ca: 30%, ct: 30%, asg: 40%
    double calculateTotal() const
    {
        return (ca * 0.3) + (ct * 0.3) + (asg * 0.4);
    }
};

// List to store contacts
vector<Person> contacts;

// Function to display all contacts
void getAllPhoneNumbers()
{
    if (contacts.empty())
    {
        cout << "No contacts available.\n";
    }
    else
    {
        cout << "\nContacts:\n";
        for (const auto &contact : contacts)
        {
            cout << "Name: " << contact.getName()
                 << ", Phone: " << contact.getTelNo() << "\n";
        }
    }
}

// Function to add a new contact
void add(const string &name, const string &telNo)
{
    contacts.emplace_back(name, telNo);
    cout << name << " has been added.\n";
}

// Function to remove a contact by phone number
void remove(const string &telNo)
{
    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        if (it->getTelNo() == telNo)
        {
            cout << it->getName() << " has been removed.\n";
            contacts.erase(it);
            return;
        }
    }
    cout << "Contact not found.\n";
}

// Function to search for a contact by phone number
void get(const string &telNo)
{
    for (const auto &contact : contacts)
    {
        if (contact.getTelNo() == telNo)
        {
            cout << "Found: " << contact.getName()
                 << " - " << contact.getTelNo() << "\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void calculateModules() {
    // Create a list of modules
    vector<Module> modules;
    
    // Add modules to the list
    modules.emplace_back("Programming", 80, 70, 90);
    modules.emplace_back("Mathematics", 70, 60, 80);
    modules.emplace_back("Database", 85, 75, 95);

    // Calculate and display total scores
    for (const auto &module : modules)
    {
        cout << "Module: " << module.getName()
             << ", Total: " << module.calculateTotal() << "\n";
    }
}

// Main menu function
void mainMenu()
{
    int option;
    do
    {
        cout << "\n---------------- Main Menu ----------------\n"
             << "[1] List the phone numbers\n"
             << "[2] Add a new contact\n"
             << "[3] Remove a contact\n"
             << "[4] Search for a phone number\n"
             << "[0] Exit\n"
             << "-------------------------------------------\n"
             << "Enter your option: ";
        cin >> option;

        if (option == 1)
        {
            getAllPhoneNumbers();
        }
        else if (option == 2)
        {
            string name, phone;
            cout << "Enter contact name: ";
            cin >> ws; // Clear input buffer
            getline(cin, name);
            cout << "Enter phone number: ";
            cin >> phone;
            add(name, phone);
        }
        else if (option == 3)
        {
            string phone;
            cout << "Enter the phone number to remove: ";
            cin >> phone;
            remove(phone);
        }
        else if (option == 4)
        {
            string phone;
            cout << "Enter the phone number to search: ";
            cin >> phone;
            get(phone);
        }
        else if (option != 0)
        {
            cout << "Invalid option. Please try again.\n";
        }
    } while (option != 0);

    cout << "Exiting...\n";
}

int main()
{
   calculateModules();
    return 0;
}