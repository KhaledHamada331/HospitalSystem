#include <iostream>
using namespace std;
struct patient
{
    int id;
    string name, disease;
    int age;
    patient *next;
};
class hospital
{
private:
    patient *head;

    // This function checks if the ID is already in use
    patient *findPatient(int id)
    {
        patient *location = head;
        while (location)
        {
            if (location->id == id)
            {
                return location;
            }
            else
            {
                location = location->next;
            }
        }
        return nullptr;
    }

public:
    hospital()
    {
        head = nullptr;
    }

    void addPatient()
    {
        patient *newPatient = new patient;

        while (true)
        {
            cout << "Enter the patient ID: ";
            cin >> newPatient->id;

            if (cin.fail())
            {
                cout << "Invalid input for ID. Please enter a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (findPatient(newPatient->id))
            {
                cout << "This ID is already in use. Please enter a unique ID.\n";
                continue;
            }

            break;
        }

        cout << "Enter the patient name: ";
        cin >> ws;
        getline(cin, newPatient->name);

        cout << "Enter the patient age: ";
        cin >> newPatient->age;
        if (cin.fail())
        {
            cout << "Invalid input for age. Operation cancelled.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            delete newPatient;
            return;
        }

        cout << "Enter the patient disease: ";
        cin >> ws;
        getline(cin, newPatient->disease);

        newPatient->next = head;
        head = newPatient;

        cout << "Patient added successfully!\n";
    }

    void del(int id)
    {
        patient *location = head;
        patient *prelocation = nullptr;
        bool found = false;
        while (location)
        {
            if (location->id == id)
            {
                if (location == head)
                {
                    head = location->next;
                }
                else
                {
                    prelocation->next = location->next;
                }
                found = true;
                cout << "You have deleted → " + location->name << endl;
                delete (location);
                break;
            }
            else
            {
                prelocation = location;
                location = location->next;
            }
        }
        if (!found)
        {
            cout << "This ID was not found\n";
        }
    }

    void search(int id)
    {
        if (!findPatient(id))
        {
            cout << "This ID was not found\n";
        }
        else
        {
            patient *Patient = findPatient(id);
            cout << "Patient found : " + Patient->name << endl;
        }
    }

    void retrive(int id)
    {
        if (!findPatient(id))
        {
            cout << "This ID was not found\n";
        }
        else
        {
            patient *Patient = findPatient(id);
            cout << "The patient id is " + to_string(Patient->id);
            cout << "\nThe patient name is " + Patient->name;
            cout << "\nThe patient age is " + to_string(Patient->age);
            cout << "\nThe patient disease is " + Patient->disease << endl;
        }
    }

    void update(int id)
    {
        if (!findPatient(id))
        {
            cout << "This id not founded\n";
        }
        else
        {
            patient *Patient = findPatient(id);
            int option = 0;
            cout << "What would you like to update?\n";
            cout << "1- Patient name\n";
            cout << "2- Patient age\n";
            cout << "3- Patient disease\n";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "Enter the patient's new name: ";
                cin >> ws;
                getline(cin, Patient->name);
                cout << "\nInformation has been updated\n";
                break;
            case 2:
                cout << "Enter the patient's new age: ";
                cin >> Patient->age;
                if (cin.fail())
                {
                    cout << "Invalid input for age. Update cancelled.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else
                {
                    cout << "\nInformation has been updated\n";
                }
                break;
            case 3:
                cout << "Enter the patient's new disease: ";
                cin >> ws;
                getline(cin, Patient->disease);
                cout << "\nInformation has been updated\n";
                break;
            default:
                cout << "Invalid input\n";
            }
        }
    }
};