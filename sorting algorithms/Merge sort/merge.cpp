/*It is an implementation of merge step in merge sort Algorithm.
The Function merge takes two arrays sroted in ascending order and 
prints the combined array after which it deletes all the arrays.*/

#include <iostream>

/*Function to get the length of the array*/

void get_len(int* len)
{
    std::cin >> *len;
    if (*len <= 0)
    {
        std::cout << "Invalid Input!" << std::endl;
        exit(1);
    }
    return;
}

/*Function to get the contents of the array*/

void get_array(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for (int i = 0; i < (n-1); i++)
    {
        if (arr[i] > arr[i+1])
        {
            std::cout << "The array must be in ascending order." << std::endl;
            exit(1);
        }
    }
    return;
}

/*Function to print the contents of the array*/

void print_array(int* array, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}

/*Function to delete the array*/

void delete_array(int* array)
{
    delete[] array;
    return;
}

/*Function for the merge step in merge sort Algoritm.*/

void merge(int* arr_1, int l1, int* arr_2, int l2)
{
    int* arr = new int[l1 + l2];

    /*Check for memory allocation errors.*/

    if (arr == nullptr)
    {
        std::cout << "Memory allocation error!" << std::endl;
        delete[] arr_1;
        delete[] arr_2;
        delete[] arr;
        exit(1);
    }

    int i,j;
    i = j = 0;

    while (i < l1 && j < l2)
    {
        if (arr_1[i] > arr_2[j])
        {
            arr[i + j] = arr_2[j];
            j++;
        }
        else if (arr_1[i] < arr_2[j])
        {
            arr[i + j] = arr_1[i];
            i++; 
        }
        else
        {
            arr[i + j + 1] = arr[i + j] = arr_1[i];
            i++;
            j++;
        }
    }

    if (i < l1)
    {
        for (int k = i; k < l1; k++)
        {
            arr[k + j] = arr_1[k];
            i++;
        }
    }

    if (j < l2)
    {
        for (int k = j; k < l2; k++)
        {
            arr[k + i] = arr_2[k];
            j++;
        }
    }

    print_array(arr, l1 + l2);
    delete_array(arr_1);
    delete_array(arr_2);
    delete_array(arr);
}

int main(void)
{
    int l1,l2;
    std::cout << "Enter the length of the first array." << std::endl;
    get_len(&l1);
    std::cout << "Enter the length of the second array." << std::endl;
    get_len(&l2);
    int* arr_1 = new int[l1];
    int* arr_2 = new int[l2];

    /*Check for memory allocation errors.*/

    if (arr_1 == nullptr || arr_2 == nullptr)
    {
        std::cout << "Memory allocation error!" << std::endl;
        delete[] arr_1;
        delete[] arr_2;
    }

    std::cout << "Enter the contents of the first array." << std::endl;
    get_array(arr_1, l1);
    std::cout << "Enter the contents of the second array." << std::endl;
    get_array(arr_2, l2);
    merge(arr_1, l1, arr_2, l2);
    
    return 0;

}
