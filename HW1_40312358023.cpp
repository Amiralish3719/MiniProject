#include <iostream>
#include <string> 

using namespace std;

struct student
{
    string name;
    long long int studentID;
    int units;
    float gpa;
    string securitycode;
    student* next;
};

void addStudent(student*& head, const string& name, long long int studentID, int units, float gpa, const string& securityCode)
{
    student* newstudent = new student;
    newstudent->name = name;
    newstudent->studentID = studentID;
    newstudent->units = units;
    newstudent->gpa = gpa;
    newstudent->securitycode = securityCode;
    newstudent->next = nullptr;

    if (head == nullptr) {
        head = newstudent;
        return;
    }

    student* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newstudent;
};



bool deleteStudent(student*& head, long long int studentID)
{
        if (head == nullptr) return false;

    if (head->studentID == studentID) {
        student* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    student* prev = head;
    student* curr = head->next;

    while (curr != nullptr) {
        if (curr->studentID == studentID) {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
};


student* searchStudent(student* head, long long int studentID)
{
        student* temp = head;
    while (temp != nullptr) {
        if (temp->studentID == studentID)
            return temp;
        temp = temp->next;
    }
    return nullptr;
};

bool updateStudent(student* head, long long int studentID, int newUnits, float newGPA)
{
        student* student = searchStudent(head, studentID);
        if (student == nullptr) return false;

    student->units = newUnits;
    student->gpa = newGPA;
    return true;

};
void displayAllRecords(student* head)
{
        if (head == nullptr) {
        cout << "The library is empty." << endl;
        return;
    }

    student* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->name
             << ", studentID: " << temp->studentID
             << ", units: " << temp->units
             << ", gpa: " << temp->gpa
             << ", securitycode: " << temp->securitycode
             << endl;
        temp = temp->next;
    }
};


int main() {
    int choice;

    student* Student = nullptr;
    string inputName, securitycode;
    int inputUnits;
    long long int inputID;
    float inputGPA;

    while (true) {
        cout << "\n================================================================================\n";
        cout << "*                 Student Record System (Linked List Implementation)           *\n";
        cout << "================================================================================\n";
        cout << "*  [1] Add New Student                                                          *\n";
        cout << "*  [2] Delete a Student by StudentID                                            *\n";
        cout << "*  [3] Find a Student by StudentID                                              *\n";
        cout << "*  [4] Update a Student's GPA                                                   *\n";
        cout << "*  [5] Display All Student Records                                              *\n";
        cout << "*  [0] Exit Program                                                             *\n";
        cout << "================================================================================\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cin.ignore();
            cout << "Invalid input. Please enter a number from 0 to 5: ";
        }
        cin.ignore();

        if (choice == 1) {
            cout << "\n--- Add New Student ---\n";
            cout << "Enter Student Name: ";
            getline(cin, inputName);

            cout << "Enter Student ID: ";
            while (!(cin >> inputID)) {
                cin.ignore();
                cout << "Invalid input. Enter a valid Student ID: ";
            }
            cin.ignore();

            cout << "Enter Number of Units: ";
            while (!(cin >> inputUnits)) {
                cin.ignore();
                cout << "Invalid input. Enter valid number of units: ";
            }
            cin.ignore();

            cout << "Enter GPA: ";
            while (!(cin >> inputGPA)) {
                cin.ignore();
                cout << "Invalid input. Enter valid GPA: ";
            }
            cin.ignore();

            cout << "Enter securitycode: ";
            getline(cin, securitycode);

            addStudent(Student, inputName, inputID, inputUnits, inputGPA, securitycode);
            cout << "Student added successfully.\n";

        } else if (choice == 2) {
            cout << "\n--- Delete Student ---\n";
            cout << "Enter Student ID to delete: ";
            while (!(cin >> inputID)) {
                cin.ignore();
                cout << "Invalid input. Enter a valid Student ID: ";
            }
            cin.ignore();

            if (deleteStudent(Student, inputID))
                cout << "Student deleted successfully.\n";
            else
                cout << "Student not found.\n";

        } else if (choice == 3) {
            cout << "\n--- Search Student ---\n";
            cout << "Enter Student ID to search: ";
            while (!(cin >> inputID)) {
                cin.ignore();
                cout << "Invalid input. Enter a valid Student ID: ";
            }
            cin.ignore();

            student* found = searchStudent(Student, inputID);
            if (found) {
                cout << "Name: " << found->name
                     << ", studentID: " << found->studentID
                     << ", units: " << found->units
                     << ", gpa: " << found->gpa
                     << ", securitycode: " << found->securitycode
                     << endl;
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 4) {
            cout << "\n--- Update Student GPA ---\n";
            cout << "Enter Student ID to update: ";
            while (!(cin >> inputID)) {
                cin.ignore();
                cout << "Invalid input. Enter a valid Student ID: ";
            }
            cin.ignore();

            cout << "Enter new units: ";
            while (!(cin >> inputUnits)) {
                cin.ignore();
                cout << "Invalid input. Enter valid units: ";
            }
            cin.ignore();

            cout << "Enter new GPA: ";
            while (!(cin >> inputGPA)) {
                cin.ignore();
                cout << "Invalid input. Enter valid GPA: ";
            }
            cin.ignore();

            if (updateStudent(Student, inputID, inputUnits, inputGPA))
                cout << "Student updated successfully.\n";
            else
                cout << "Student not found.\n";

        } else if (choice == 5) {
            cout << "\n--- Displaying All Records ---\n";
            displayAllRecords(Student);

        } else if (choice == 0) {
            cout << "Program Terminated. Goodbye!\n";
            break;

        } else {
            cout << "Invalid choice. Please enter a number from 0 to 5.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.get();
    }

    return 0;
}