#include <iostream>
using namespace std;

int LinearSearch(int A[], int n, int key)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == key)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        cout << "Search Found!!!" << endl;
        cout << "The position of number " << key << " is " << pos << "." << endl;
    }
    else
    {
        cout << "The number is not available in the array." << endl;
    }
}

int main()
{
    int n, key;
    cout << "******************************" << endl;
    cout << "\tLINEAR SEARCH" << endl;
    cout << "******************************" << endl << endl;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a[i];
    }
    cout << "Enter the element to search: ";
    cin >> key;
    LinearSearch(a, n, key);
}
