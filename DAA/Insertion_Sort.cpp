#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << endl << "Pass " << i << ":";
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;

        // Display the array after each comparison
        for (int k = 0; k < n; k++)
            cout << "\t" << A[k];
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cout << "\t\t==================" << endl;
    cout << "\t\t  Insertion Sort  " << endl;
    cout << "\t\t==================" << endl;

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

    // Perform insertion sort
    insertionSort(A, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}