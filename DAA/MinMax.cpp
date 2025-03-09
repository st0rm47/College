#include <iostream>
using namespace std;

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
        // Divide the problem into smaller subproblems
        int mid = (l + r) / 2;

        // Recursive calls for left and right halves
        int min1, max1;
        findMinMax(A, l, mid, min1, max1);

        int min2, max2;
        findMinMax(A, mid + 1, r, min2, max2);

        // Merge results
        min = (min1 < min2) ? min1 : min2;
        max = (max1 > max2) ? max1 : max2;
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
    findMinMax(A, l, r, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
