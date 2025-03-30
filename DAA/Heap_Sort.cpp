#include<iostream>
using namespace std;

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    cout << endl << "[Heapify] Called on index " << i << " : ";
    printArray(arr, n);

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) 
    {
        cout << " - Swapping " << arr[i] << " and " << arr[largest] << endl;
        swap(arr[i], arr[largest]);
        cout << " - After swap: ";
        printArray(arr, n);
        heapify(arr, n, largest); // Recursive heapify
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) 
{
    cout << "=============================" << endl;
    cout << "  Step 1: Building Max Heap  " << endl;
    cout << "=============================" << endl;
    for(int i = n/2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i);
    }
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << "===================" << endl;
    cout << "  Step 2: Sorting  " << endl;
    cout << "===================" << endl;
    for(int i = n - 1; i > 0; i--) 
    {
        cout << "[Swap Max] Swapping " << arr[0] << " and " << arr[i] << endl;
        swap(arr[0], arr[i]);
        cout << " - After swap: ";
        printArray(arr, n);
        heapify(arr, i, 0);
    }
    cout << "------------------------------------" << endl;
}

int main()
{
    cout << "\t\t=============" << endl;
    cout << "\t\t  Heap Sort  " << endl;
    cout << "\t\t=============" << endl;

    int n;
    int A[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << endl;

    cout << "Original array: ";
    printArray(A, n);
    cout << endl;

    // Perform heap sort
    heapSort(A, n);

    cout << endl << "Final Sorted Array: ";
    printArray(A, n);

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
