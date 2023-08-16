/*
This program is an impliementation of Insertion-sort algorithm.
It starts by asking the user to enter the size of the array.
Then it asks the user to enter the elements of the array.
Then it sorts the array using Insertion-sort algorithm.
Later it prints the sorted array.
*/

#include <iostream>
// using namespace std; Not a good practice!

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

// The insertion sort algorithms implementation

void insertion_sort(int n, int* arr) {
    //Compare and sort (if necessary) the first two elements!
    int key;//temporary variable used for sorting
    if (arr[0] > arr[1]) {
        key = arr[0];
        arr[0] = arr[1];
        arr[1] = key;
    }
    //Now the first two elements are sorted!
    for (int i = 2; i < n; i++) {
        //Boundary cases
        if (arr[i] <= arr[0]) {
            key = arr[i];
            for (int k = i - 1; k >= 0; k--) {
                arr[k+1] = arr[k];
            }
            arr[0] = key;
        }
        else if (arr[i] >= arr[i-1]) {
            continue;
        }
        //Boundary cases done!
        else {
            for(int k = 0; k < i-1; k++) {
                if ((arr[k] <= arr[i]) && (arr[i] <= arr[k+1])) {
                    int temp = arr[i];
                    for (int a = i-1; a > k ; a--) {
                        arr[a+1] = arr[a];
                    }
                    arr[k+1] = temp;
                }
                else {
                    continue;
                }
            }
        }
    }
}

// Function for printing the array

void print_arr(int n, int* arr) {
    std::cout << "Here is the sorted array in ascending order!\n";
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
    insertion_sort(n,arr);
    print_arr(n,arr);
    delete[] arr;
    return 0;
}
