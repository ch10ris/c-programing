#include <iostream>
#include <string>

using namespace std;

int main() {
    string studentName;
    double marks, attendance;
    string scholarshipStatus;

    
    cout << "Enter student name: ";
    getline(cin, studentName);
    cout << "Enter exam marks (0-100): ";
    cin >> marks;
    cout << "Enter attendance percentage (0-100): ";
    cin >> attendance;

    if (marks >= 70) {
        if (attendance >= 80) {
            scholarshipStatus = "Full Scholarship";
        } else {
            scholarshipStatus = "Partial Scholarship";
        }
    } 
    else if (marks >= 50) {
        if (attendance >= 85) {
            scholarshipStatus = "Partial Scholarship";
        } else {
            scholarshipStatus = "No Scholarship";
        }
    } 
    else { 
        scholarshipStatus = "No Scholarship";
    }

    
    cout << "\n--- Scholarship Results ---" << endl;
    cout << "Student Name: " << studentName << endl;
    cout << "Scholarship Status: " << scholarshipStatus << endl;

    return 0;
}
