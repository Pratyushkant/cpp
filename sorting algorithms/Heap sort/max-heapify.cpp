/*
This program is an implementation of MAX-HEAPIFY
Function. It assumes that left and right sub-trees are max-heaps
and only checks the parents and updates them (if necessarily) recursively.
*/
#include <iostream>
#include <cmath>

// Function to get the length of the array

void get_len(int* n) {
    std::cout << "Enter the length of the array\n";
    std::cin >> *n;
    if (*n <= 0) {
        std::cout << "Invalid input!";
        exit(1);  // Using exit(1) terminates the execution of main() also.
    }
    if (*n == 1) {
        std::cout << "Array must have at least two elements!\n";
        exit(0);
    }
}

// Function to get the contents of the array

void get_arr(int n, int* arr) {
    if (arr == NULL){
        std::cout << "Oops! Not enough memory!";
        exit(1);   // Using exit(1) terminates the execution of main() also.
    }
    std::cout << "Enter the array elements.(Make sure to press enter key after each element entered!)\n";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

// The max_heapify algorithms implementation

int max(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void max_heapify(int n, int* array)
{
    int i;
    int a = (int)(floor(n/2)-1);
    for (i = 0; i <= a; i++)
    {
        int b;
        if (2*i + 2 < n)
        {
            b = max(array[2*i + 1], array[2*i + 2]);
        }
        else
        {
            b = max(array[2*i + 1], array[2*i + 1]);
        }
        
        if (array[i] >= b)
        {
            continue;
        }
        else if (array[2*i + 1] >= array[2*i + 2])
        {
            // swap array[i] with array[2*i + 1]
            int c = array[i];
            array[i] = array[2*i + 1];
            array[2*i + 1] = c;
            continue;
        }
        else
        {
            int c = array[i];
            array[i] = array[2*i + 2];
            array[2*i + 2] = c;
            continue;
        }
    }
}


// Function for printing the array

void print_arr(int n, int* arr) {
    std::cout << "Here is the max heapified array!\n";
    for (int i = 0; i < n; i++) {
        std::cout << " " << arr[i];
    }
    std:: cout << "\n";
}

// The main function

int main(void) {
    int n;
    get_len(&n);
    int* arr = new int[n];
    get_arr(n, arr);
    max_heapify(n,arr);
    print_arr(n,arr);
    delete[] arr;
    return 0;
}
