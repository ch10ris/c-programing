#include <iostream>
using namespace std;


// Task 1: Library Book Management

class Book
{
    string title;
    string author;
    int copies;

public:

    void inputDetails()
    {
        cout << "Enter book title: ";
        cin >> title;

        cout << "Enter author name: ";
        cin >> author;

        cout << "Enter number of copies: ";
        cin >> copies;
    }


    void borrowBook()
    {
        if(copies > 0)
        {
            copies--;
            cout << "Book borrowed successfully!\n";
        }
        else
        {
            cout << "No copies available!\n";
        }
    }


    void displayDetails()
    {
        cout << "\nBook Details\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Available Copies: " << copies << endl;
    }
};



// Task 2: Student Fee Management

class Student
{
    string name;
    int admissionNumber;
    double feeBalance;


public:

    void inputStudent()
    {
        cout << "\nEnter student name: ";
        cin >> name;

        cout << "Enter admission number: ";
        cin >> admissionNumber;

        cout << "Enter fee balance: ";
        cin >> feeBalance;
    }


    void makePayment()
    {
        double payment;

        cout << "Enter payment amount: ";
        cin >> payment;


        if(payment <= feeBalance)
        {
            feeBalance -= payment;
            cout << "Payment successful!\n";
        }
        else
        {
            cout << "Payment is greater than balance!\n";
        }
    }


    void displayStatus()
    {
        cout << "\nStudent Fee Status\n";
        cout << "Name: " << name << endl;
        cout << "Admission Number: " << admissionNumber << endl;
        cout << "Remaining Balance: " << feeBalance << endl;
    }

};



// Main Function

int main()
{

    // Book Object
    Book book1;

    cout << "LIBRARY BOOK MANAGEMENT SYSTEM\n";

    book1.inputDetails();

    book1.borrowBook();

    book1.displayDetails();



    Student student1;

    cout << "\n\nSTUDENT FEE MANAGEMENT SYSTEM\n";

    student1.inputStudent();

    student1.makePayment();

    student1.displayStatus();



    return 0;
}
