#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    string id, name, address, dob, mobile_no, doj;
    string marital_status, department, work_location, ctc;
    string social_insurance, email;

public:
    void enterData() {
        cout << "** PERSONAL DETAILS **" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Address: ";
        cin >> address;
        cout << "Enter Date of Birth: ";
        cin >> dob;
        cout << "Is Employee Married?: ";
        cin >> marital_status;

        cout << "** WORK DETAILS **" << endl;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Date of Joining: ";
        cin >> doj;
        cout << "Enter Work Department: ";
        cin >> department;
        cout << "Enter Work Location: ";
        cin >> work_location;
        cout << "Enter CTC: ";
        cin >> ctc;
        cout << "Enter Social Insurance ID: ";
        cin >> social_insurance;

        cout << "** CONTACT DETAILS **" << endl;
        cout << "Enter Mobile No: ";
        cin >> mobile_no;
        cout << "Enter Email: ";
        cin >> email;
    }

    void showData(int index) const {
        cout << "\nData of Employee " << index + 1 << endl;
        cout << "** PERSONAL DETAILS **" << endl;
        cout << "Name: " << name << "\nAddress: " << address
             << "\nDOB: " << dob << "\nMarital Status: " << marital_status << endl;

        cout << "** WORK DETAILS **" << endl;
        cout << "ID: " << id << "\nDate of Joining: " << doj
             << "\nDepartment: " << department << "\nLocation: " << work_location
             << "\nCTC: " << ctc << "\nSocial Insurance: " << social_insurance << endl;

        cout << "** CONTACT DETAILS **" << endl;
        cout << "Mobile No: " << mobile_no << "\nEmail: " << email << endl;
    }

    string getId() const {
        return id;
    }

    void updateData() {
        cout << "Enter new data for Employee ID " << id << endl;
        enterData();
    }
};

class EmployeeSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        int n;
        cout << "How many employees do you want to add? ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            Employee emp;
            cout << "\nEntering details for Employee " << i + 1 << endl;
            emp.enterData();
            employees.push_back(emp);
        }
    }

    void displayEmployees() const {
        if (employees.empty()) {
            cout << "No employee data entered yet." << endl;
            return;
        }

        for (size_t i = 0; i < employees.size(); ++i) {
            employees[i].showData(i);
        }
    }

    void searchEmployee() const {
        if (employees.empty()) {
            cout << "No data available to search." << endl;
            return;
        }

        string id;
        cout << "Enter Employee ID to search: ";
        cin >> id;

        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                emp.showData(0); // index isn't needed here
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    void updateEmployee() {
        if (employees.empty()) {
            cout << "No data available to update." << endl;
            return;
        }

        string id;
        cout << "Enter Employee ID to update: ";
        cin >> id;

        for (auto& emp : employees) {
            if (emp.getId() == id) {
                emp.updateData();
                cout << "Employee data updated successfully." << endl;
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    void deleteAllData() {
        char confirm;
        cout << "Are you sure you want to delete all data? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
            employees.clear();
            cout << "All data has been deleted." << endl;
        } else {
            cout << "Deletion canceled." << endl;
        }
    }
};

int main() {
    EmployeeSystem system;
    int choice;

    while (true) {
        cout << "\n===== EMPLOYEE RECORD MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add Employee\n2. Show All Employees\n3. Search Employee\n";
        cout << "4. Update Employee\n5. Delete All Records\n6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: system.addEmployee(); break;
            case 2: system.displayEmployees(); break;
            case 3: system.searchEmployee(); break;
            case 4: system.updateEmployee(); break;
            case 5: system.deleteAllData(); break;
            case 6: return 0;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
}
