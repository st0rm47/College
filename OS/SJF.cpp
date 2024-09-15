#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <climits>

using namespace std;

// Structure to represent a process
struct Process 
{
    int id;              // Process ID
    int burstTime;       // Burst Time 
    int arrivalTime;     // Arrival Time
    int waitingTime;     // Waiting Time
    int turnAroundTime;  // Turn Around Time
    int responseTime;    // Response Time
    bool completed;      // Flag to check if the process is completed
};

// Function to find the process with the shortest burst time that has arrived
int findShortestBurstTimeProcess(const vector<Process>& processes, int currentTime) 
{
    // Find the process with the shortest burst time among the arrived processes
    int idx = -1;
    int minBurstTime = INT_MAX;

    // Iterate over all processes to find the one with the shortest burst time
    for (int i = 0; i < processes.size(); i++) 
    {
        if (!processes[i].completed && processes[i].arrivalTime <= currentTime &&
            processes[i].burstTime < minBurstTime) {
            minBurstTime = processes[i].burstTime;
            idx = i;
        }
    }
    return idx;
}
// Function to calculate waiting time, turn around time, and response time for each process
void calculateTimes(vector<Process>& processes) 
{
    int n = processes.size();
    int currentTime = 0, completed = 0;  // Keep track of the current time and number of completed processes
    while (completed < n) 
    {
        int idx = findShortestBurstTimeProcess(processes, currentTime);
        if (idx != -1) 
        {
            // Process found, update its times
            processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
            processes[idx].responseTime = processes[idx].waitingTime;
            processes[idx].turnAroundTime = processes[idx].waitingTime + processes[idx].burstTime;
            currentTime += processes[idx].burstTime;
            processes[idx].completed = true;
            completed++;
        } 
        else 
        {
            // No process is ready, increment current time
            currentTime++;
        }
    }
}

// Function to display waiting time, turn around time, and response time for each process in table format
void displayProcessTimes(const vector<Process>& processes) 
{
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl;
    cout << "| Process | Arrival Time | Burst Time | Turn Around Time | Waiting Time | Response Time |" << endl;
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl;

    for (const Process& p : processes) 
    {
        cout << "|   P" << setw(3) << left << p.id
             << "  |      " << setw(8) << left << p.arrivalTime
             << "|     " << setw(7) << left << p.burstTime
             << "|       " << setw(11) << left << p.turnAroundTime
             << "|      " << setw(8) << left << p.waitingTime
             << "|       " << setw(8) << left << p.responseTime << "|\n";
    }
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl << endl;
}

/// Function to display the Gantt chart for SJF scheduling
void displayGanttChart(vector<Process> processes) {
int n = processes.size();
    int currentTime = 0, completed = 0;  // Keep track of the current time and number of completed processes
    vector<int> ganttOrder;               // To store the order of processes for the Gantt chart
    vector<int> completionTimes(n, 0);   // To store the completion times of each process

    while (completed < n) 
    {
        int idx = findShortestBurstTimeProcess(processes, currentTime);

        // If a process is found, execute it
        if (idx != -1) 
        {
            processes[idx].completed = true;
            ganttOrder.push_back(processes[idx].id); // Add to Gantt chart order
            currentTime += processes[idx].burstTime;
            completionTimes[ganttOrder.size() - 1] = currentTime;
            completed++;
        } 
        else 
        {
            // If no process is ready, CPU is idle, increment time
            currentTime++;
        }
    }

    // Display the Gantt chart
    cout << endl << "Gantt Chart: " << endl;

    cout << "+";
    for (const Process &p : processes)
        cout << "-------+";
    cout << endl << "|";

    for (int id : ganttOrder)
        cout << "  P" << id << "   |";
    cout << endl << "+";

    for (int i = 0; i < ganttOrder.size(); i++)
        cout << "-------+";
    cout << endl;

    // Display the timeline
    cout << "0";
    for (int time : completionTimes)
        cout << setw(8) << time;
    cout << endl << endl;
}

// Function to calculate average waiting time and turn around time
void calculateAverages(const vector<Process> &processes)
{
    int totalWaitingTime = 0, totalTurnAroundTime = 0, totalRespsonseTime = 0;
    int n = processes.size();

    // Calculate total waiting time and total turn around time
    for (const Process &p : processes)
    {
        totalWaitingTime += p.waitingTime;
        totalTurnAroundTime += p.turnAroundTime;
        totalRespsonseTime += p.responseTime;
    }
    cout << "Average Turn Around Time: " << (float)totalTurnAroundTime / n << endl;
    cout << "Average Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Response Time: " << (float)totalRespsonseTime / n << endl;
}

int main() 
{
    cout << "\t\t==========================" << endl;
    cout << "\t\t  SJF Process Scheduling  " << endl;
    cout << "\t\t==========================" << endl;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) 
    {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].completed = false;
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) { return a.arrivalTime < b.arrivalTime; });

    // Display Gantt chart
    displayGanttChart(processes);

    // Calculate times
    calculateTimes(processes);

    // Display process information with waiting time, turn around time, and response time
    displayProcessTimes(processes);

    // Display average times
    calculateAverages(processes);

    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
