#include <iostream>
#include <vector>
#include <string>
using namespace std;

//STUDENT CLASS
class Student {
private:
    int rollNo;
    string name;
    string branch;
    int year;
    float marks;
public:
    Student() {}    // Default constructor
    // Parameterized constructor
    Student(int r, string n, string b, int y, float m) {
        rollNo = r;
        name = n;
        branch = b;
        year = y;
        marks = m;
    }
    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Branch: ";
        cin >> branch;
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Branch: " << branch << endl;
        cout << "Year: " << year << endl;
        cout << "Marks: " << marks << endl;
    }

    int getRollNo() const {
        return rollNo;
    }
};

//ADMIN CLASS
class Admin {
private:
    vector<Student> students;

public:
    void addStudent() {
        Student s;
        s.input();
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void viewStudents() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (const auto &s : students) {
            s.display();
            cout << "-------------------\n";
        }
    }

    void searchStudent(int roll) {
        for (const auto &s : students) {
            if (s.getRollNo() == roll) {
                cout << "Student Found:\n";
                s.display();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void deleteStudent(int roll) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNo() == roll) {
                students.erase(it);
                cout << "🗑 Student deleted successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
};
// MAIN FUNCTION
int main() {
    Admin admin;
    int choice, roll;

    cout << "Student Management System\n";

    do {
        cout << "\n1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                admin.addStudent();
                break;
            case 2:
                admin.viewStudents();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> roll;
                admin.searchStudent(roll);
                break;
            case 4:
                cout << "Enter Roll No to delete: ";
                cin >> roll;
                admin.deleteStudent(roll);
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);
    return 0;
}
