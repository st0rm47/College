#include <iostream>
#include <cmath>

using namespace std;

void merge_sort(int A[], int l, int r);
void merge(int array[], int l, int m, int r);

int main()
{
    int i, n;
    cout << "******************************" << endl;
    cout << "\tMERGE SORT" << endl;
    cout << "******************************" << endl << endl;

    cout << "Enter the size of array:\t";
    cin >> n;

    const int size = 100; 

    int array[size];
    for (i = 0; i < n; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }

    merge_sort(array, 0, n - 1);
    cout << "\nThe sorted array using MERGE SORT is given as:" << endl;
    for (i = 0; i < n; i++)
    {
        cout << array[i] << "\t";
    }
    return 0;
}

void merge_sort(int A[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = floor((l + r) / 2);
        merge_sort(A, l, m);
        merge_sort(A, m + 1, r);
        merge(A, l, m + 1, r);
    }
}

void merge(int array[], int l, int m, int r)
{
    int x, y, i, k;
    int* B = new int[r + 1];
    x = l;
    y = m;
    k = l;

    while (x < m && y <= r)
    {
        if (array[x] < array[y])
        {
            B[k++] = array[x++];
        }
        else
        {
            B[k++] = array[y++];
        }
    }
    while (x < m)
    {
        B[k++] = array[x++];
    }
    while (y <= r)
    {
        B[k++] = array[y++];
    }
    for (i = l; i <= r; i++)
    {
        array[i] = B[i];
    }
}
