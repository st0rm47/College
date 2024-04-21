// WAP to demonstrate memory allocation.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    cout << "\t\t=============================" << endl;
    cout << "\t\t  Dynamic Memory Allocation  " << endl;
    cout << "\t\t=============================" << endl;

    int *ptr, *ptr1;
    int n, i;

    // Using Malloc
    cout << "Using Malloc" << endl;
    cout << "Enter the value of n: ";
    cin >> n;
    ptr = (int *)malloc(n * sizeof(int));
    cout << "Values from the array are: ";
    for (i = 0; i < n; i++)
        cout << ptr[i] << " ";

    // Using Calloc
    cout << endl << endl << "Using Calloc" << endl;
    cout << "Enter new value of n: ";
    cin >> n;
    ptr1 = (int *)calloc(n, sizeof(int));
    cout << "Values from the array are: ";
    for (i = 0; i < n; i++)
        cout << ptr1[i] << " ";

    // Entering values into the array
    cout << endl << "Entering values into the array: ";
    for (i = 0; i < n; i++)
        cin >> ptr1[i];
    cout << "Values from the array are: ";
    for (i = 0; i < n; i++)
        cout << ptr1[i] << " ";

    // Using Realloc
    cout << endl << endl << "Using Realloc" << endl;
    cout << "New Size of Array = 10" << endl;
    int *new_ptr = (int *)realloc(ptr1, 10 * sizeof(int));
    cout << "Entering values into the array: ";
    for (i = n; i < 10; i++)
        cin >> new_ptr[i];
    cout << "Values from the array are: ";
    for (i = 0; i < 10; i++)
        cout << new_ptr[i] << " ";

    // Free dynamically allocated memory
    free(new_ptr);
    return 0;
}


