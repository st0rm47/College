#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void firstfit(vector<int> &partitionSize, const vector<int> &processSize, int m, int n)
{
    vector<int> allocation(n, -1), holeLeft(n, 0);

    // Perform First Fit allocation
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Check if partition can accommodate the process
            if (partitionSize[j] >= processSize[i])
            {
                allocation[i] = j;                                       // Assign partition to process
                partitionSize[j] -= processSize[i];          // Reduce partition size
                holeLeft[i] = partitionSize[j];                // Calculate hole in partition	
	    break; 		       // Exit the loop after finding the first suitable partition       
   }
        }
    }

     // Print the table after allocation
    cout << "+-------------+--------------+---------------+-----------+" << endl;
    cout << "| Process No. | Process Size | Partition No. | Hole Left |" << endl;
    cout << "+-------------+--------------+---------------+-----------+" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "|     " << setw(2) << i + 1 << "      |" << setw(8) << processSize[i] << 
        "      |";
        if (allocation[i] != -1)
            cout << "      " << setw(2) << allocation[i] + 1 << "       |" << setw(7) << 
            holeLeft[i] << "    |" << endl;
        else
            cout << " Not Allocated |    N/A    |" << endl;
        cout << "+-------------+--------------+---------------+-----------+" << endl;
    }
}

int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  First Fit Allocation  " << endl;
    cout << "\t\t========================" << endl;

    int m, n;
    cout << "Enter the number of partitions: ";
    cin >> m;
    vector<int> partitionSize(m);
    cout << endl << "Enter the size of each partition:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Partition " << i + 1 << ": ";
        cin >> partitionSize[i];
    }
    cout << endl << "Enter the number of processes: ";
    cin >> n;
    vector<int> processSize(n);
    cout << endl << "Enter the size of each process:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }
    firstfit(partitionSize, processSize, m, n);
    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
