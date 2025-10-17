#include <iostream>
#include <string> 

using namespace std;

struct student
{
    string name;
    int studentID;
    int units;
    float gpa;
    string securitycode;
    student* next;
};

void addStudent(student*& head, const string& name, int studentID, int units, float gpa, const string& securityCode)
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



bool deleteStudent(student*& head, int studentID)
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


student* searchStudent(student* head, int studentID)
{
        student* temp = head;
    while (temp != nullptr) {
        if (temp->studentID == studentID)
            return temp;
        temp = temp->next;
    }
    return nullptr;
};

bool updateStudent(student* head, int studentID, int newUnits, float newGPA)
{};
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

    string inputName;
    int inputID, inputUnits;
    float inputGPA;

    while (true) {
        cout << "\n";
        cout << "================================================================================\n";
        cout << "*                                                                              *\n";
        cout << "*         Student Record System (Linked List Implementation)                    *\n";
        cout << "*                                                                              *\n";
        cout << "================================================================================\n";
        cout << "*                                                                              *\n";
        cout << "*  [1] Add New Student                                                          *\n";
        cout << "*  [2] Delete a Student by StudentID                                            *\n";
        cout << "*  [3] Find a Student by StudentID                                              *\n";
        cout << "*  [4] Update a Student's GPA                                                   *\n";
        cout << "*  [5] Display All Student Records                                              *\n";
        cout << "*                                                                              *\n";
        cout << "*  [0] Exit Program                                                            *\n";
        cout << "*                                                                              *\n";
        cout << "================================================================================\n";
        cout << "\n";
        cout << "  Enter your choice: ";

        cin >> choice;

        cin.ignore(); 

        if (choice == 1) {
            cout << "\n--- Add New Student ---\n";
            cout << "Enter Student Name: ";
            getline(cin, inputName); 
            cout << "Enter Student ID: ";
            cin >> inputID;
            cout << "Enter Number of Units: ";
            cin >> inputUnits;
            cout << "Enter GPA: ";
            cin >> inputGPA;
            cout << "\n-> Student data received. (Record would be added here)\n";
        } else if (choice == 2) {
            cout << "\n--- Delete Student ---\n";
            cout << "Enter Student ID to delete: ";
            cin >> inputID;
            cout << "\n-> Deletion request for ID " << inputID << " received. (Record would be deleted here)\n";
        } else if (choice == 3) {
            cout << "\n--- Search Student ---\n";
            cout << "Enter Student ID to search: ";
            cin >> inputID;
            cout << "\n-> Searching for ID " << inputID << "... (Record would be displayed here)\n";
        } else if (choice == 4) {
            cout << "\n--- Update Student GPA ---\n";
            cout << "Enter Student ID to update: ";
            cin >> inputID;
            cout << "Enter new GPA: ";
            cin >> inputGPA;
            cout << "\n-> Update request for ID " << inputID << " received. (GPA and security codes would be updated here)\n";
        } else if (choice == 5) {
            cout << "\n--- Displaying All Records ---\n";
            cout << "-> (All student records would be printed here)\n";
        } else if (choice == 0) {
            cout << "\n================================================================================\n";
            cout << "*                         Program Terminated. Goodbye!                         *\n";
            cout << "================================================================================\n";
            break;
        } else {
            cout << "\n!!! Invalid choice. Please enter a number from 0 to 5.\n";
        }

        cout << "\n\nPress Enter to return to the main menu...";
        cin.get(); 
    }

    return 0;
}