#include <iostream>
using namespace std;

// Function to find the minimum and maximum element in an array
void findMinMax(int A[], int l, int r, int &min, int &max)
{
    if (l == r)
    {
        min = A[l];
        max = A[l];
    }
    else if (l == r - 1)
    {
        if (A[l] < A[r])
        {
            min = A[l];
            max = A[r];
        }
        else
        {
            min = A[r];
            max = A[l];
        }
    }
    else
    {
        // Divide the array into two parts 
        int mid = (l + r) / 2;
        int min1, max1;

        // Recursively find the minimum and maximum of the two parts
        findMinMax(A, l, mid, min, max);
        findMinMax(A, mid + 1, r, min1, max1);

        if (min1 < min)
            min = min1;
        if (max1 > max)
            max = max1;
    }
}

int main()
{
    cout << "\t\t===================" << endl;
    cout << "\t\t  Min-Max Finding  " << endl;
    cout << "\t\t===================" << endl;

    int n;
    int A[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << endl;

    int l = 0;
    int r = n - 1;
    int min, max;

    // Perform min-max finding
    findMinMax(A, l, r, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
