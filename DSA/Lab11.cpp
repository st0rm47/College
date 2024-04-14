// WAP to find position of number using linear search.

#include <iostream>
using namespace std;

// Function to perform linear search
void linearSearch(int A[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            cout << "Element found at position " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

int main()
{
    cout << "\t\t===================" << endl;
    cout << "\t\t   Linear Search   " << endl;
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

    // Perform linear search
    linearSearch(A, n, key);

    return 0;
}