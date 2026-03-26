#include <iostream>
using namespace std;

int main() {
    // Dynamic C++ array - size determined at runtime
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;
    int* dynamicArray = new int[size];      // size is determined at runtime, 
                                            //  created on the heap, and 
                                            //  must be manually destroyed
    
    // Initialize dynamic array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }
    
    // Dynamic array - flexible size, manual cleanup required
    cout << "Dynamic array size: " << size << endl;
    cout << "Size of dynamic array in bytes: " << sizeof(int) * size << endl;
    cout << "Size of dynamic array in bytes: " << sizeof(dynamicArray) << endl;
    
    // show how elemetns can be added to the dynamic array
    for (int i = 0; i < size; i++) {
        cout << "dynamicArray[" << i << "]: " << dynamicArray[i] << endl;
    }   
    
    // MUST manually free dynamic memory
    delete[] dynamicArray;
    
    return 0;
}