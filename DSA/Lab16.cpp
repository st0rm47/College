#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;

        // Move elements of A[0...i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}

int main()
{
    cout << "\t\t================" << endl;
    cout << "\t\tInsertion Sort" << endl;
    cout << "\t\t================" << endl;

    int n;
    int A[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << endl;

    // Display original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    // Perform insertion sort
    insertionSort(A, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}