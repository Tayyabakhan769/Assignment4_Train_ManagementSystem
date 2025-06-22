#include <iostream>
#include <vector>
using namespace std;

const int NUM_BOGGIES = 10;
const int ROWS = 5;
const int COLS = 4;

class Train {
    vector<vector<vector<char>>> boggies;

public:
    Train() {
        boggies.resize(NUM_BOGGIES, vector<vector<char>>(ROWS, vector<char>(COLS, '-')));
        boggies[0][2][1] = 'X';
        boggies[1][2][2] = 'X';
        boggies[2][0][1] = 'X';
        boggies[2][3][1] = 'X';
        boggies[3][1][3] = 'X';
        boggies[4][0][2] = 'X';
        boggies[4][3][1] = 'X';
    }

    void displayBogie(int bogieNum) {
        cout << "\n************** Bogie " << bogieNum << " - Seating Layout *************\n";
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << "[" << boggies[bogieNum - 1][i][j] << "] ";
            }
            cout << "\n";
        }
        cout << "----------------------------------------------------\n";
        cout << "Legend: [-] = Available | [X] = Pre-booked or Booked\n";
    }

    void displayFullTrain() {
        cout << "\n====================================================\n";
        cout << "        === FULL TRAIN SEATING PLAN DISPLAY ===\n";
        cout << "====================================================\n\n";

        for (int b = 0; b < NUM_BOGGIES; b++) {
            cout << "------------ Bogie " << (b + 1) << " ------------\n";
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    cout << "[" << boggies[b][i][j] << "] ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
        cout << "====================================================\n";
        cout << "Legend:\n[-] = Vacant Seat\n[X] = Pre-Booked or Already Booked\n";
        cout << "====================================================\n";
    }

    bool bookSeat(int bogieNum, int row, int col) {
        char &seat = boggies[bogieNum - 1][row - 1][col - 1];
        if (seat == 'X') {
            cout << ">>> Seat is PRE-BOOKED and cannot be booked!\n";
            return false;
        } else {
            seat = 'X';
            cout << ">>> Seat successfully BOOKED!\n";
            return true;
        }
    }
};

int main() {
    Train train;
    int choice;

    cout << "====================================================\n";
    cout << "      *** TRAIN MANAGEMENT SYSTEM - PAKISTAN RAILWAYS ***\n";
    cout << "====================================================\n";

    while (true) {
        cout << "\n===================== MAIN MENU =====================\n";
        cout << "1. View Bogie Seating\n";
        cout << "2. Book a Seat\n";
        cout << "3. View Full Train Seating Plan\n";
        cout << "4. Exit\n";
        cout << "====================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int bogieNum;
            cout << "Enter bogie number to view (1 - 10): ";
            cin >> bogieNum;
            if (bogieNum < 1 || bogieNum > NUM_BOGGIES) {
                cout << "Invalid bogie number!\n";
                continue;
            }
            train.displayBogie(bogieNum);
        } else if (choice == 2) {
            int bogieNum;
            cout << "----------------------------------------------------\n";
            cout << "Enter Bogie Number to Book In (1 - 10): ";
            cin >> bogieNum;
            if (bogieNum < 1 || bogieNum > NUM_BOGGIES) {
                cout << "Invalid bogie number!\n";
                continue;
            }

            bool bookingLoop = true;
            while (bookingLoop) {
                train.displayBogie(bogieNum);

                int row, col;
                cout << "\nEnter Row (1-5): ";
                cin >> row;
                cout << "Enter Column (1-4): ";
                cin >> col;
                if (row < 1 || row > ROWS || col < 1 || col > COLS) {
                    cout << "Invalid seat position!\n";
                    continue;
                }

                train.bookSeat(bogieNum, row, col);

                cout << "----------------------------------------------------\n";
                cout << "What would you like to do next?\n";
                cout << "1. Book another seat in this bogie\n";
                cout << "2. Choose another bogie\n";
                cout << "3. Return to main menu\n";
                cout << "Enter your choice: ";
                int nextChoice;
                cin >> nextChoice;

                if (nextChoice == 1) continue;
                else if (nextChoice == 2) {
                    cout << "Enter new bogie number (1 - 10): ";
                    cin >> bogieNum;
                    if (bogieNum < 1 || bogieNum > NUM_BOGGIES) {
                        cout << "Invalid bogie number! Returning to main menu.\n";
                        bookingLoop = false;
                    }
                } else {
                    bookingLoop = false;
                }
            }
        } else if (choice == 3) {
            train.displayFullTrain();
        } else if (choice == 4) {
            cout << "====================================================\n";
            cout << ">>> Thank you for using Pakistan Railways Booking System!\n";
            cout << ">>> Have a safe and pleasant journey!\n";
            cout << "====================================================\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
