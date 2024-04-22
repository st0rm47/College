#include <iostream>
using namespace std;

// Function to perform binary search
void binarySearch(int A[], int l, int r, int key)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == key)
            cout << "Element found at position " << mid << endl;
        else if (A[mid] > key)
            binarySearch(A, l, mid - 1, key);
        else
            binarySearch(A, mid + 1, r, key);
    }
    else
        cout << "Element not found" << endl;
}

int main()
{
    cout << "\t\t===================" << endl;
    cout << "\t\t   Binary Search   " << endl;
    cout << "\t\t===================" << endl;
    
    int n;
    int A[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int key,l,r;
    l = 0;
    r = n - 1;
    cout << "Enter the element to search: ";
    cin >> key;

    // Perform binary search
    binarySearch(A, l, r, key);

    return 0;
}
