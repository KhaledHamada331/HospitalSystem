#include <iostream>
#include "Headers/header.h"
using namespace std;

int main()
{
    hospital h;
    while (true)
    {
        int option = -1;
        cout << "\n==== Hospital Management System ====\n";
        cout << "1 - Add new patient\n";
        cout << "2 - Delete patient\n";
        cout << "3 - Search for patient\n";
        cout << "4 - Retrieve patient information\n";
        cout << "5 - Update patient information\n";
        cout << "0 - Exit\n";
        cout << "Select an option: ";
        cin >> option;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        int id = -1;
        switch (option)
        {
        case 1:
            h.addPatient();
            break;
        case 2:
            cout << "Enter patient ID to delete: ";
            cin >> id;
            if (cin.fail())
            {
                cout << "Invalid ID input.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            h.del(id);
            break;
        case 3:
            cout << "Enter patient ID to search: ";
            cin >> id;
            if (cin.fail())
            {
                cout << "Invalid ID input.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            h.search(id);
            break;
        case 4:
            cout << "Enter patient ID to retrieve info: ";
            cin >> id;
            if (cin.fail())
            {
                cout << "Invalid ID input.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            h.retrive(id);
            break;
        case 5:
            cout << "Enter patient ID to update: ";
            cin >> id;
            if (cin.fail())
            {
                cout << "Invalid ID input.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            h.update(id);
            break;
        case 0:
            cout << "Exiting the system. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
