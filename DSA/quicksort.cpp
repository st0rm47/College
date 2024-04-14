#include <iostream>
#include <cmath>

using namespace std;

int z = 0, array_size;

void quick_sort(int A[], int l, int r);
int partition(int array[], int partition_position, int r);

int main()
{
    int i;
    cout << "******************************" << endl;
    cout << "\tQUICK SORT" << endl;
    cout << "******************************" << endl << endl;

    cout << "Enter the size of array:\t";
    cin >> array_size;

    int* array = new int[array_size]; 
    for (int i = 0; i < array_size; i++)
    {
        cout << "array[" << i << "] = ";
        cin >> array[i];
    }

    quick_sort(array, 0, array_size - 1);
    delete[] array; 
    return 0;
}

void quick_sort(int A[], int l, int r)
{
    int n, k = 0, i, p;

    if (l < r)
    {
        z += 1;
        p = partition(A, l, r);
        cout << "\n\nPass " << z << endl;
        for (i = 0; i < array_size; i++)
        {
            cout << A[i] << "\t";
        }
        quick_sort(A, l, p - 1);
        quick_sort(A, p + 1, r);
    }
}

int partition(int array[], int partition_position, int r)
{
    int x, j, i, temp, k;
    x = array[partition_position];
    i = partition_position + 1;
    j = r;
    while (i <= j)
    {
        while (array[i] < x && i <= r)
        {
            i++;
        }
        while (array[j] > x && j >= partition_position)
        {
            j--;
        }
        if (i < j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            cout << "\n\nPass " << z << endl;
            cout << endl;
            for (k = 0; k < array_size; k++)
            {
                cout << array[k] << "\t";
            }
            z += 1;
        }
    }
    temp = array[partition_position];
    array[partition_position] = array[j];
    array[j] = temp;
    return j;
}
