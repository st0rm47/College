#include <iostream>
using namespace std;

void Bubblesort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        cout << "PASS " << i + 1 << ":\n";
        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            for (int k = 0; k < n; k++)
            {
                cout << A[k] << "\t";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n, i;
    cout << "******************************\n";
    cout << "\tBUBBLE SORT\n";
    cout << "******************************\n";

    cout << "Enter the number of data in array:\t";
    cin >> n;
    const int MAX_SIZE = 100; // Setting a maximum size for the array
    int a[MAX_SIZE]; // Declaring a static array with a fixed size
    cout << "Enter the elements:\n";
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "The sorted array using BUBBLE SORT is given as:\n";
    Bubblesort(a, n);

    return 0;
}
