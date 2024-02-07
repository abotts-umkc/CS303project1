#include "Header.h"

using namespace std;

// this loads the initial array from the txt file and fills it with the integers
ArrayOperations::ArrayOperations(int initialSize) : size(0), capacity(initialSize) {
    arr = new int[capacity];
}

ArrayOperations::~ArrayOperations() {
    delete[] arr;
}

//this helps you find if a integer exists in any of the index values
int ArrayOperations::checkIfExists(int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i; 
        }
    }
    return -1; 
}

//this is how i can change the integer inside of an index in the array value 
void ArrayOperations::modifyValueAtIndex(int index, int newValue, int& oldValue, int& newValueOut) {
    if (index < 0 || index >= size) throw IndexError();
    oldValue = arr[index];
    arr[index] = newValue;
    newValueOut = newValue;
}

//this is how i add new integers into the array and it lets the array update its size to include new data
void ArrayOperations::addInteger(int value) {
    
    if (size == capacity) {
        resize(); 
    }
    arr[size++] = value;
    
}

//this is how i replace the value with 0 or remove an index value and the integer within it
//this also shifts all of the other data values to the left if i remove the index value
void ArrayOperations::replaceOrRemoveAtIndex(int index, bool remove) {
    if (index < 0 || index >= size) throw IndexError();
    if (remove) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1]; 
        }
        --size;
    }
    else {
        arr[index] = 0; 
    }
}

//helps to resize the array
void ArrayOperations::resize() {
    capacity = capacity * 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

//this is what originally loads in all of the integers from the txt file
void ArrayOperations::readFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw FileError();
    }

    int value;
    while (inputFile >> value) {     
        addInteger(value);
    }
    inputFile.close();
}

