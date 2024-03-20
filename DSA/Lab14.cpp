// Write a program to implement quick sort algorithm in ascending order.

#include <iostream>
using namespace std;

// Function to partition the array into two subarrays
int partition(int A[], int left, int right)
{
    int x = left;
    int y = right;
    int pivot = A[left], temp;
    while (x < y)
    {
        while (A[x] <= pivot)
            x++;
        while (A[y] > pivot)
            y--;
        if (x < y)
        {
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
    A[left] = A[y];
    A[y] = pivot;
    return y;
}

// Function to perform quick sort
void quickSort(int A[], int left, int right)
{
    if (left < right)
    {
        int p = partition(A, left, right);
        quickSort(A, left, p - 1);
        quickSort(A, p + 1, right);
    }
}
int main()
{
    cout << "\t\t================" << endl;
    cout << "\t\t   Quick Sort   " << endl;
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

    int l = 0;     // Add variable assignment for l
    int r = n - 1; // Add variable assignment for r

    // Perform quick sort
    quickSort(A, l, r);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}