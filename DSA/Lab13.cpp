// Write a program to implement shell sort algorithm in ascending order and display each pass.

#include <iostream>
using namespace std;

// Function to perform shell sort
void shellSort(int A[], int n)
{
    int gap = n / 2;
    int pass = 1;
    while (gap > 0)
    {
        cout << "Pass " << pass << " Gap " << gap << ":" << endl;
        // Perform shell sort for the current gap
        for (int i = gap; i < n; i++)
        {
            int temp = A[i];
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
            {
                A[j] = A[j - gap];
            }
            A[j] = temp;

            // Display the array after each pass
            for (int k = 0; k < n; k++)
            {
                cout << "\t" << A[k];
            }
            cout << endl;
        } 
        pass++;
        gap /= 2;
        cout << endl;
    }
}
int main()
{
    cout << "\t\t================" << endl;
    cout << "\t\t   Shell Sort   " << endl;
    cout << "\t\t================" << endl;

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

    // Perform shell sort
    shellSort(A, n);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
