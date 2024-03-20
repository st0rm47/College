// Write a program to implement merge sort algorithm in ascending order and display each pass.

#include <iostream>
using namespace std;

// Function to merge two sorted sub arrays arr[left...mid] and arr[mid+1...right]
void merge(int A[], int left, int mid, int right)
{
    // Initialize indices for the two subarrays and the merged array
    int x = left;
    int y = mid + 1;
    int k = left;
    int temp[100];

    // Merge elements from both subarrays into the temporary array
    while (x <= mid && y <= right)
    {
        if (A[x] <= A[y])
        {
            temp[k] = A[x];
            x++;
        }
        else
        {
            temp[k] = A[y];
            y++;
        }
        k++;
    }
    // Copy any remaining elements from the first subarray
    while (x <= mid)
    {
        temp[k] = A[x];
        x++;
        k++;
    }
    // Copy any remaining elements from the second subarray
    while (y <= right)
    {
        temp[k] = A[y];
        y++;
        k++;
    }

    // Copy the merged elements back to original array
    for (int i = left; i <= right; i++)
    {
        A[i] = temp[i];
    }
}

// Function to perform merge sort
void mergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // Sort first and second halves
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);

        // Merge the sorted halves
        merge(A, left, mid, right);
    }
}

int main()
{
    cout << "\t\t================" << endl;
    cout << "\t\t   Merge Sort   " << endl;
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

    int l = 0;     // Add variable assignment for l
    int r = n - 1; // Add variable assignment for r

    // Perform merge sort
    mergeSort(A, l, r);

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}