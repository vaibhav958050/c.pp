#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to hold Criminal Data
struct Criminal {
    string id;
    string name;
    string crime;
    string age;
};

// Function to save data to a CSV file (Excel Compatible)
void saveToExcel(const vector<Criminal>& records) {
    ofstream file("CrimeRecords.csv"); // This file opens directly in Excel

    // Writing the Header (Columns in Excel)
    file << "Case ID,Name,Crime Type,Age" << endl;

    for (const auto& c : records) {
        file << c.id << "," << c.name << "," << c.crime << "," << c.age << endl;
    }

    file.close();
    cout << "\n[+] Data successfully synced to CrimeRecords.csv" << endl;
}

int main() {
    vector<Criminal> records;
    int choice;

    while (true) {
        cout << "\n======================================";
        cout << "\n   CRIME RECORD MANAGEMENT SYSTEM     ";
        cout << "\n======================================";
        cout << "\n1. Add New Record";
        cout << "\n2. View All Records (Terminal)";
        cout << "\n3. Export to Excel (CSV)";
        cout << "\n4. Exit";
        cout << "\nSelect Option: ";
        cin >> choice;

        if (choice == 1) {
            Criminal c;
            cout << "Enter Case ID: "; cin >> c.id;
            cout << "Enter Criminal Name: "; cin.ignore(); getline(cin, c.name);
            cout << "Enter Type of Crime: "; getline(cin, c.crime);
            cout << "Enter Age: "; cin >> c.age;
            
            records.push_back(c);
            cout << "\nRecord added to temporary memory!";
            
        } else if (choice == 2) {
            cout << "\n--- Current Records ---\n";
            cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Crime" << "Age" << endl;
            for (const auto& c : records) {
                cout << left << setw(10) << c.id << setw(20) << c.name << setw(20) << c.crime << c.age << endl;
            }
            
        } else if (choice == 3) {
            saveToExcel(records);
            
        } else if (choice == 4) {
            cout << "Exiting System..." << endl;
            break;
        } else {
            cout << "Invalid Option. Try again." << endl;
        }
    }

    return 0;
}