#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Shellsort(vector<int>& A, int n)
{
    int gap, i, j, temp, k, l = 1;
    gap = floor(n / 2);
    while (gap > 0)
    {
        cout << "PASS " << l << ":\n";
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i;
            while (j >= gap && A[j - gap] > temp)
            {
                A[j] = A[j - gap];
                j = j - gap;
            }
            A[j] = temp;
            for (k = 0; k < n; k++)
            {
                cout << A[k] << "\t";
            }
            cout << "\n";
        }
        gap = floor(gap / 2);
        l++;
    }
}

int main()
{
    int n, i;
    cout << "******************************\n";
    cout << "\tSHELL SORT\n";
    cout << "******************************\n\n";
    cout << "Enter the number of data in array:\t";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements:\n";
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    cout << "The sorted array using SHELL SORT is given as:\n";
    Shellsort(a, n);

    return 0;
}
