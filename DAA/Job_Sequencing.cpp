#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Structure to represent a job
struct Job
{
    int id, profit, deadline;
};

// Function to compare jobs by profit for sorting
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

// Function to solve Job Sequencing and show the process
void jobSequencing(Job arr[], int n)
{
    int step = 1;
    int total_profit = 0;

    // Step 1: Sort jobs by profit
    cout << endl << "Step " << step << ": Sorting jobs by profit (descending)" << endl;
    sort(arr, arr + n, compare);
    cout << "+-------+--------+----------+" << endl;
    cout << "| JobID | Profit | Deadline |" << endl;
    cout << "+-------+--------+----------+" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| " << setw(5) << arr[i].id << " | "
             << setw(6) << arr[i].profit << " | "
             << setw(8) << arr[i].deadline << " |" << endl;
    }
    cout << "+-------+--------+----------+" << endl;
    step++;

    // Step 2: Find maximum deadline
    int max_deadline = 0;
    cout << endl << "Step " << step << ": Finding maximum deadline" << endl;
    cout << "+-------+----------+" << endl;
    cout << "| JobID | Deadline |" << endl;
    cout << "+-------+----------+" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "| " << setw(5) << arr[i].id << " | "
             << setw(8) << arr[i].deadline << " |" << endl;
        if (arr[i].deadline > max_deadline)
            max_deadline = arr[i].deadline;
    }
    cout << "+-------+----------+" << endl;
    cout << "Maximum deadline = " << max_deadline << endl;
    step++;

    // Step 3: Initialize slots
    int slots[max_deadline];
    for (int i = 0; i < max_deadline; i++)
        slots[i] = -1; // -1 indicates empty slot

    // Step 4: Schedule jobs
    cout << endl << "Step " << step << ": Scheduling jobs" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "+-------+--------+----------+" << endl;
        cout << "| JobID | Profit | Deadline |" << endl;
        cout << "+-------+--------+----------+" << endl;
        cout << "| " << setw(5) << arr[i].id << " | "
             << setw(6) << arr[i].profit << " | "
             << setw(8) << arr[i].deadline << " |" << endl;
        cout << "+-------+--------+----------+" << endl;

        // Try to schedule job in the latest possible slot
        cout << "+-------+----------+-------------------+" << endl;
        cout << "| Slot  |  Status  |    Assigned Job   |" << endl;
        cout << "+-------+----------+-------------------+" << endl;
        for (int j = min(max_deadline, arr[i].deadline) - 1; j >= 0; j--)
        {   
            cout << "| " << setw(5) << j << " | ";
            if (slots[j] == -1)
            {
                slots[j] = arr[i].id;
                total_profit += arr[i].profit;
                cout << "Empty    | Assigned to Job " << arr[i].id << " |" << endl;
                cout << "+-------+----------+-------------------+" << endl;

                // Print current schedule
                cout << endl << "Schedule after step " << step << ": ";
                for (int k = 0; k < max_deadline; k++)
                {
                    if (slots[k] == -1)
                    cout << "_ ";
                    else
                    cout << "J" << slots[k] << " ";
                }
                cout << "(Profit = " << total_profit << ")" << endl;
                step++;
                break;
            }
            else
            {
                cout << "Occupied | Job " << slots[j] << "          |" << endl;
                cout << "+--------+----------+----------------+" << endl;
            }
        }
    }
    // Print final schedule
    cout << "Final Schedule: ";
    for (int i = 0; i < max_deadline; i++)
    {
        if (slots[i] != -1)
            cout << "J" << slots[i] << " ";
    }
    cout << endl << "Maximum profit achievable: " << total_profit << endl;
}

int main()
{
    cout << "\t\t==========================" << endl;
    cout << "\t\t  Job Sequencing Problem  " << endl;
    cout << "\t\t==========================" << endl;

    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Job arr[n];
    cout << "Enter job ID, profit, and deadline for each job:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Job " << i << " (ID Profit Deadline): ";
        cin >> arr[i].id >> arr[i].profit >> arr[i].deadline;
    }

    // Perform Job Sequencing
    jobSequencing(arr, n);

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
