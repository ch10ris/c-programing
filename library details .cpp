#include <iostream>
using namespace std;

int main() {
    
    int bookID, dueDate, returnDate;
    int daysOverdue, fineRate, fineAmount;


    cout << "Enter Book ID: ";
    cin >> bookID;
    cout << "Enter Due Date : ";
    cin >> dueDate;
    cout << "Enter Return Date : ";
    cin >> returnDate;

    
    daysOverdue = returnDate - dueDate;


    if (daysOverdue <= 0) {
        fineRate = 0;
        fineAmount = 0;
    } else if (daysOverdue <= 7) {
        fineRate = 20;
        fineAmount = daysOverdue * fineRate;
    } else if (daysOverdue <= 14) {
        fineRate = 50;
        fineAmount = daysOverdue * fineRate;
    } else {
        fineRate = 100;
        fineAmount = daysOverdue * fineRate;
    }

    
    cout << "\n Library Fine Details \n";
    cout << "Book ID: " << bookID << endl;
    cout << "Due Date: " << dueDate << endl;
    cout << "Return Date: " << returnDate << endl;
    cout << "Days Overdue: " << daysOverdue << endl;
    cout << "Fine Rate (Ksh per day): " << fineRate << endl;
    cout << "Total Fine Amount (Ksh): " << fineAmount << endl;

    return 0;
}
