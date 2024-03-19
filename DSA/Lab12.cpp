// Write a program to implement bubble sort algorithm in ascending order and display each pass.

#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass " << i + 1 << ":";
        // Perform bubble sort for the current pass
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if current element is greater than the next
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            // Display the array after each comparison
            for (int k = 0; k < n; k++)
            {
                cout << "\t" << A[k];
            }
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    cout << "\t\t=================" << endl;
    cout << "\t\t   Bubble Sort   " << endl;
    cout << "\t\t=================" << endl;

    int n;
    int A[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    // Display original array
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    // Perform bubble sort
    bubbleSort(A, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
