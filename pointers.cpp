#include <iostream>
using namespace std;

int main() {
    // An array of integers.
    int numbers[] = {10, 20, 30, 40, 50};
    
    // We initialize a pointer that points to the first element of the array.
    int* ptr = numbers;

    // The size of the array.
    // sizeof(numbers): total number of bytes occupied by the array numbers.
    // sizeof(numbers[0]): number of bytes occupied by a single element of the array, which is the first element in this case.
    // => sizeof(numbers) / sizeof(numbers[0]) the number of elements in the array.
    int size = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Array elements using pointer arithmetic:" << endl;

    // Loop through the array using pointer arithmetic.
    for (int i = 0; i < size; ++i) {
        // Display the slot address
        cout << "Slot:" << ptr << " " << endl;

        // Element at the current pointer address (slot).
        cout << "Value at slot: " << *ptr << " " << endl;

        // Slot:0x7ffe9e78ebc0 
        // Value at slot: 10 

        // Slot:0x7ffe9e78ebc4 
        // Value at slot: 20 

        // Slot:0x7ffe9e78ebc8 
        // Value at slot: 30 

        // Slot:0x7ffe9e78ebcc 
        // Value at slot: 40 
        
        // Slot:0x7ffe9e78ebd0 
        // Value at slot: 50 

        // Move the pointer to the next element of the array.
        ptr++;
    }
    
    cout << endl;

    // Move the pointer backwards by half the length of the array.
    // For example, if size = 7, ptr moves 3 elements back
    ptr -= size / 2;

    // Calculate the distance between two pointers.
    // The following gives the number of elements between ptr and &numbers[4].
    // the & operator is used to get the address of the fifth element in the array numbers
    cout << "The pointer 'ptr' is " << (&numbers[4] - ptr) << " elements away from the fifth element." << endl;

    // Using a pointer to modify the array values.
    *ptr = 100;  // This will change numbers[0] to 100.
    ptr[3] = 400; // This will change numbers[3] to 400 using array syntax.

    cout << "Modified array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
