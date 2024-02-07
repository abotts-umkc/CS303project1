#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>   //includes that make the program work from libraries
#include <fstream>
#include <stdexcept>
#include <string>

class ArrayOperations {
public:
    ArrayOperations(int initialSize); // Constructor + destructor
    ~ArrayOperations(); 

    // functions
    int checkIfExists(int value);
    void modifyValueAtIndex(int index, int newValue, int& oldValue, int& newValueOut);
    void addInteger(int value);
    void replaceOrRemoveAtIndex(int index, bool remove);
    void readFromFile(const std::string& filename);
    int getSize() const { return size; }

    // exception help classes
    class IndexError {}; 
    class SizeError {};  
    class FileError {};

    
private:
    int* arr; 
    int capacity; 
    int size; // size of the array

    void resize(); // resizes the array 
};

#endif 