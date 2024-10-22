#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Person class based on the class diagram
class Person {
private:
    string name;
    string telNo;

public:
    Person(const string &name, const string &telNo) : name(name), telNo(telNo) {}

    void setName(const string &name) { this->name = name; }
    void setTelNo(const string &telNo) { this->telNo = telNo; }

    string getName() const { return name; }
    string getTelNo() const { return telNo; }
};

// Module class
class Module {
private:
    string name;
    double ca;
    double ct;
    double asg;

public:
    Module(const string &name, double ca, double ct, double asg)
    {
        this->name = name;
        this->ca = ca;
        this->ct = ct;
        this->asg = asg;
    }

    void setName(const string &name) { this->name = name; }
    void setCa(double ca) { this->ca = ca; }
    void setCt(double ct) { this->ct = ct; }
    void setAsg(double asg) { this->asg = asg; }

    string getName() const { return name; }
    double getCa() const { return ca; }
    double getCt() const { return ct; }
    double getAsg() const { return asg; }

    double calculateTotal() const {
        return (ca * 0.3) + (ct * 0.3) + (asg * 0.4);
    }
};

// Contact Manager class
class ContactManager {
private:
    vector<Person> contacts;

public:
    void getAllPhoneNumbers() const {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
        } else {
            cout << "\nContacts:\n";
            for (const auto &contact : contacts) {
                cout << "Name: " << contact.getName()
                     << ", Phone: " << contact.getTelNo() << "\n";
            }
        }
    }

    void addContact(const string &name, const string &telNo) {
        contacts.emplace_back(name, telNo);
        cout << name << " has been added.\n";
    }

    void removeContact(const string &telNo) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getTelNo() == telNo) {
                cout << it->getName() << " has been removed.\n";
                contacts.erase(it);
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void getContact(const string &telNo) const {
        for (const auto &contact : contacts) {
            if (contact.getTelNo() == telNo) {
                cout << "Found: " << contact.getName()
                     << " - " << contact.getTelNo() << "\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

void calculateModules() {
    vector<Module> modules = {
        Module("Programming", 80, 70, 90),
        Module("Mathematics", 70, 60, 80),
        Module("Database", 85, 75, 95)
    };

    for (const auto &module : modules) {
        cout << "Module: " << module.getName()
             << ", Total: " << module.calculateTotal() << "\n";
    }
}

enum MenuOption {
    EXIT,
    LIST_PHONE_NUMBERS,
    ADD_CONTACT,
    REMOVE_CONTACT,
    SEARCH_PHONE_NUMBER
};

void mainMenu(ContactManager &contactManager) {
    int option;
    do {
        cout << "\n---------------- Main Menu ----------------\n"
             << "[1] List the phone numbers\n"
             << "[2] Add a new contact\n"
             << "[3] Remove a contact\n"
             << "[4] Search for a phone number\n"
             << "[0] Exit\n"
             << "-------------------------------------------\n"
             << "Enter your option: ";
        cin >> option;

        switch (option) {
            case LIST_PHONE_NUMBERS: {
                contactManager.getAllPhoneNumbers();
                break;
            }
            case ADD_CONTACT: {
                string name, phone;
                cout << "Enter contact name: ";
                cin >> ws;
                getline(cin, name);
                cout << "Enter phone number: ";
                cin >> phone;
                contactManager.addContact(name, phone);
                break;
            }
            case REMOVE_CONTACT: {
                string phone;
                cout << "Enter the phone number to remove: ";
                cin >> phone;
                contactManager.removeContact(phone);
                break;
            }
            case SEARCH_PHONE_NUMBER: {
                string phone;
                cout << "Enter the phone number to search: ";
                cin >> phone;
                contactManager.getContact(phone);
                break;
            }
            case EXIT: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    } while (option != EXIT);
}

int main()
{
    mainMenu();
    return 0;
}
