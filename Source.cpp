#include "Header.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;


    int main() {
        ArrayOperations arrayOps(10); 
        cout << "Attempting to read from A1input.txt..." << endl;

        try {
            arrayOps.readFromFile("A1input.txt");
            //check array size after reading in the txt file 
            cout << "Current index size: " << arrayOps.getSize() - 1 << endl << endl; 
        }
        catch (ArrayOperations::FileError&) {
            cout << "Failed to open file A1input.txt" << endl;
            return 1; // this error is here for if the txt file does not open
        }

        //this is the menu below where the commands are all controlled by the user
        int choice;
        do {
            cout << "Menu\n"
                << "Enter 1 to check if a value exists.\n"
                << "Enter 2 to modify the value at x index.\n"
                << "Enter 3 to add a new integer to the end of the array.\n"
                << "Enter 4 to take an index of the array and remove the value or replace it with 0.\n"
                << "Enter 5 to exit the program.\n\n"
                << "Entered value - ";
            cin >> choice;

            // this cin fail below is copied repeatedly throughout the menu for the exception handling
            //whenever a user enters something wrong in the menu driven commands
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Please enter numbers only.\n";
            }
            // each of the cases below in the switch for the menu has exception handling
            // as well as the function calls for each of the commands required for the program
            // as well as an exit command for the user to exit the program

            switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to check: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter numbers only.\n";
                }
                int index = arrayOps.checkIfExists(value);
                if (index != -1) {
                    cout << "Value exists at index " << index << ".\n";
                }
                else {
                    cout << "Value does not exist.\n";
                }
                break;
            }
            case 2: {
                int index, newValue;
                cout << "Enter index: ";
                cin >> index;
                if (cin.fail() || index < 0 || index >= arrayOps.getSize()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input or index out of range. Current index max " << arrayOps.getSize() - 1 << "." << endl;
                    break; 
                }
                cout << "Enter the new value: ";
                cin >> newValue;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter a valid number.\n";
                    break; 
                }

                try {
                    int oldValue, newValueOut;
                    arrayOps.modifyValueAtIndex(index, newValue, oldValue, newValueOut);
                    cout << "Old Value: " << oldValue << ", New Value: " << newValueOut << endl;
                }
                catch (ArrayOperations::IndexError&) {               
                    cout << "Error: Attempted to modify an index that does not exist.\n";
                }
                break;
            }

            case 3: {
                int value;
                cout << "Enter new integer: ";
                cin >> value;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter numbers only.\n";
                }
                arrayOps.addInteger(value);
                break;
            }
            case 4: {
                int index;
                bool remove;
                cout << "Enter index: ";
                cin >> index;
                if (cin.fail() || index < 0 || index >= arrayOps.getSize()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input or index out of range. Current index max " << arrayOps.getSize() - 1 << "." << endl;
                    break; 
                }

                cout << "Enter 1 to remove the value or 0 to replace it with 0: ";
                cin >> remove;
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter 1 or 0.\n";
                    break; 
                }

                try {
                    if (remove) {
                        cout << "Removing index " << index << "." << endl;
                        arrayOps.replaceOrRemoveAtIndex(index, true);
                    }
                    else {
                        cout << "Updating index value " << index << " to 0." << endl;
                        arrayOps.replaceOrRemoveAtIndex(index, false);
                    }
                }
                catch (ArrayOperations::IndexError&) {
                    cout << "Error: Attempted to modify an index that does not exist.\n";
                }
                break;
            }

            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            }
        } while (choice != 5);

        return 0;
    }
    