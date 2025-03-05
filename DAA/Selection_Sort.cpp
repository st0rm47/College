#include<iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << endl << "Pass " << i + 1 << ":";
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }

        // Swap the found minimum element with the first element
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;

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
    cout << "\t\t  Selection Sort  " << endl;
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

    // Perform selection sort
    selectionSort(A, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}