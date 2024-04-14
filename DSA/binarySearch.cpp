#include <iostream>
using namespace std;

int BinarySearch(int A[], int n, int l, int r, int key)
{
    int mid;
    if (l <= r)
    {
        mid = (l + r) / 2;
        if (A[mid] == key)
        {
            cout << "Search Found!!!" << endl;
            cout << "The position of the number " << key << " is " << mid << endl;
        }
        else if (A[mid] < key)
            BinarySearch(A, n, mid + 1, r, key);
        else
            BinarySearch(A, n, l, mid - 1, key);
    }
}

int main()
{
    int n, key;
    cout << "******************************" << endl;
    cout << "\tBINARY SEARCH" << endl;
    cout << "******************************" << endl;

    cout << "Enter the size of array: ";
    cin >> n;
    int a[n], i, l, r;
    l = 0;
    r = n - 1;
    cout << "Enter the elements of array: ";
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;
    int c = 0;
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
            c++;
    }
    if (c == 0)
        cout << "The number is not in the array." << endl;
    else
        BinarySearch(a, n, l, r, key);
}
