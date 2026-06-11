#include <iostream>
#include <iomanip>
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time()

using namespace std;

const int DAYS        = 7;
const int FLOORS      = 5;
const int ROOMS       = 10;
const int BRANCHES    = 3;

const string DAY_NAMES[]    = {"Monday","Tuesday","Wednesday",
                                "Thursday","Friday","Saturday","Sunday"};
const string BRANCH_NAMES[] = {"Branch A (Nairobi CBD)",
                                "Branch B (Westlands)",
                                "Branch C (Karen)"};

void printHeader(const string& title) {
    cout << "\n" << string(60, '=') << "\n";
    cout << "  " << title << "\n";
    cout << string(60, '=') << "\n";
}

void printDivider() {
    cout << string(60, '-') << "\n";
}

void weeklyRevenueTracker() {
    printHeader("PART 1: Weekly Revenue Tracker (1D Array)");

    double revenue[DAYS];
    double total = 0.0;

    cout << "\nEnter the daily revenue (in KES) for each day:\n\n";

    for (int i = 0; i < DAYS; i++) {
        cout << "  " << left << setw(12) << DAY_NAMES[i] << ": KES ";
        cin >> revenue[i];

        // Basic validation
        while (revenue[i] < 0) {
            cout << "  Revenue cannot be negative. Re-enter: KES ";
            cin >> revenue[i];
        }
        total += revenue[i];
    }

    double average = total / DAYS;

    printDivider();
    cout << "\n  DAILY REVENUE SUMMARY\n\n";
    cout << left << setw(15) << "  Day"
         << right << setw(18) << "Revenue (KES)" << "\n";
    printDivider();

    for (int i = 0; i < DAYS; i++) {
        cout << "  " << left << setw(13) << DAY_NAMES[i]
             << right << setw(18) << fixed << setprecision(2)
             << revenue[i] << "\n";
    }

    printDivider();
    cout << "  " << left << setw(13) << "TOTAL"
         << right << setw(18) << fixed << setprecision(2)
         << total   << "\n";
    cout << "  " << left << setw(13) << "AVERAGE (daily)"
         << right << setw(18) << fixed << setprecision(2)
         << average << "\n";
    printDivider();
}

void roomOccupancy() {
    printHeader("PART 2: Room Occupancy – Single Branch (2D Array)");

    int occupancy[FLOORS][ROOMS];

    // Simulate random occupancy
    srand(static_cast<unsigned int>(time(NULL)));

    cout << "\n  Simulating room occupancy (1 = Occupied, 0 = Vacant)...\n\n";

    for (int f = 0; f < FLOORS; f++)
        for (int r = 0; r < ROOMS; r++)
            occupancy[f][r] = rand() % 2;   // 0 or 1

    // ── Display floor-by-floor grid ──
    cout << "  Room Layout:\n";
    cout << "  " << string(56, '-') << "\n";
    cout << "  Floor  |";
    for (int r = 0; r < ROOMS; r++)
        cout << " R" << setw(2) << left << (r + 1) << " |";
    cout << "  Occupied | Vacant\n";
    cout << "  " << string(56, '-') << "\n";

    int totalOccupied = 0, totalVacant = 0;

    for (int f = 0; f < FLOORS; f++) {
        int floorOccupied = 0, floorVacant = 0;

        cout << "  Fl " << (f + 1) << "   |";
        for (int r = 0; r < ROOMS; r++) {
            cout << "  " << occupancy[f][r] << "  |";
            if (occupancy[f][r] == 1) floorOccupied++;
            else                       floorVacant++;
        }

        cout << "     " << setw(5) << floorOccupied
             << "    |  " << floorVacant << "\n";

        totalOccupied += floorOccupied;
        totalVacant   += floorVacant;
    }

    cout << "  " << string(56, '-') << "\n";
    cout << "  TOTALS  |" << string(41, ' ')
         << setw(5) << totalOccupied << "    |  " << totalVacant << "\n";
    printDivider();

    cout << "\n  Summary:\n";
    cout << "    Total rooms   : " << (FLOORS * ROOMS) << "\n";
    cout << "    Occupied rooms: " << totalOccupied << "\n";
    cout << "    Vacant rooms  : " << totalVacant   << "\n";
    cout << "    Occupancy rate: "
         << fixed << setprecision(1)
         << (100.0 * totalOccupied / (FLOORS * ROOMS)) << "%\n";
    printDivider();
}

void multipleBranches() {
    printHeader("PART 3: Multi-Branch Occupancy (3D Array)");

    int chain[BRANCHES][FLOORS][ROOMS];

    // Use a different seed for variety
    srand(static_cast<unsigned int>(time(NULL)) + 42);

    cout << "\n  Assigning random occupancy across all branches...\n\n";

    for (int b = 0; b < BRANCHES; b++)
        for (int f = 0; f < FLOORS; f++)
            for (int r = 0; r < ROOMS; r++)
                chain[b][f][r] = rand() % 2;

    // ── Per-branch report ──
    int grandTotal = 0;

    for (int b = 0; b < BRANCHES; b++) {
        cout << "  " << BRANCH_NAMES[b] << "\n";
        cout << "  " << string(44, '-') << "\n";
        cout << "  Floor  | Occupied | Vacant | Occ. Rate\n";
        cout << "  " << string(44, '-') << "\n";

        int branchOccupied = 0;

        for (int f = 0; f < FLOORS; f++) {
            int floorOcc = 0;
            for (int r = 0; r < ROOMS; r++)
                if (chain[b][f][r] == 1) floorOcc++;

            int floorVac  = ROOMS - floorOcc;
            double rate   = 100.0 * floorOcc / ROOMS;

            cout << "  Floor " << (f + 1) << "  |"
                 << setw(6)  << floorOcc  << "    |"
                 << setw(5)  << floorVac  << "   | "
                 << fixed << setprecision(0) << rate << "%\n";

            branchOccupied += floorOcc;
        }

        int branchVacant = (FLOORS * ROOMS) - branchOccupied;
        double branchRate = 100.0 * branchOccupied / (FLOORS * ROOMS);

        cout << "  " << string(44, '-') << "\n";
        cout << "  Branch Total: " << branchOccupied << " occupied / "
             << branchVacant << " vacant  ("
             << fixed << setprecision(1) << branchRate << "% occupied)\n\n";

        grandTotal += branchOccupied;
    }

    int grandVacant = (BRANCHES * FLOORS * ROOMS) - grandTotal;
    double grandRate = 100.0 * grandTotal / (BRANCHES * FLOORS * ROOMS);

    printDivider();
    cout << "  CHAIN-WIDE SUMMARY\n";
    printDivider();
    cout << "  Total rooms (all branches) : " << (BRANCHES * FLOORS * ROOMS) << "\n";
    cout << "  Total occupied rooms       : " << grandTotal  << "\n";
    cout << "  Total vacant rooms         : " << grandVacant << "\n";
    cout << "  Overall occupancy rate     : "
         << fixed << setprecision(1) << grandRate << "%\n";
    printDivider();
}


int main() {
    cout << "\n";
    cout << "  *     HOTEL CHAIN MANAGEMENT SYSTEM               *\n";
    cout << "  *     Week 5 Activity – Arrays in C++             *\n";


    weeklyRevenueTracker();  
    roomOccupancy();         
    multipleBranches();      

    cout << "\n  Program complete. Have a great day!\n\n";
    return 0;
}
