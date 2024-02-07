The code creates a integer driven menu that will
allow the user to enter integers to use the commands
as required by the instructions. 

When the program starts you will see a line that says attempting to read 
in the A1input.txt file. There is a try catch to ensure that the file is 
being read properly. 
The program will then print the starting index limit as read in. 

Then the menu will print to allow the user to adjust the array as required. 
The menu is entirely filtered with try catch exceptions to ensure 
that the user does not enter any values that are not allowed 
whether it be a character instead of numeric value or an out of bounds
numeric value. 

***************EXAMPLE INITIAL LOADING OF PROGRAM*******************

Attempting to read from A1input.txt...
Current index size: 99

Menu
Enter 1 to check if a value exists.
Enter 2 to modify the value at x index.
Enter 3 to add a new integer to the end of the array.
Enter 4 to take an index of the array and remove the value or replace it with 0.
Enter 5 to exit the program.

Entered value -

*************EXAMPLE OF INCORRECT ENTRY IN MENU************

Entered value - k
Invalid input. Please enter numbers only.
Invalid choice. Please enter a number between 1 and 5.

***********EXAMPLE OF 1 COMMAND FROM MENU******************
Entered value - 1
Enter value to check: 55
Value exists at index 54.

Entered value - 1
Enter value to check: K
Invalid input. Please enter numbers only.

**********EXAMPLE OF 2 COMMAND FROM MENU******************
Entered value - 2
Enter index: 99
Enter the new value: 0
Old Value: 100, New Value: 0

Entered value - 2
Enter index: K
Invalid input or index out of range. Current index max 99.

Entered value - 2
Enter index: 99
Enter the new value: L
Invalid input. Please enter a valid number.

***********EXAMPLE OF 3 COMMAND FROM MENU**************
Entered value - 3
Enter new integer: l
Invalid input. Please enter numbers only.

Entered value - 3
Enter new integer: 101
------------ looping to 1 in menu ensure it entered 
Entered value - 1
Enter value to check: 101
Value exists at index 101.

************EXAMPLE OF 4 COMMAND FROM MENU************
Entered value - 4
Enter index: 100
Enter 1 to remove the value or 0 to replace it with 0: 1
Removing index 100.

Entered value - 4
Enter index: 100
Enter 1 to remove the value or 0 to replace it with 0: 0
Updating index value 100 to 0.

------------ looping to 1 in menu ensure it entered 
Entered value - 1
Enter value to check: 0
Value exists at index 99.

********COMMAND 5 IN THE MENU SIMPLY EXITS THE PROGRAM
