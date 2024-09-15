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
    int remainingTime;   // Remaining Burst Time
    bool completed;      // Flag to check if the process is completed
    bool firstExecution; // Flag to check if the process is executed for the first time
};

// Function to find the process with the shortest burst time that has arrived
int findShortestBurstTimeProcess(const vector<Process> &processes, int currentTime)
{
    int idx = -1;
    int minBurstTime = INT_MAX;
    for (int i = 0; i < processes.size(); i++)
    {
        if (!processes[i].completed && processes[i].arrivalTime <= currentTime &&
            processes[i].burstTime < minBurstTime)
        {
            minBurstTime = processes[i].burstTime;
            idx = i;
        }
    }
    return idx;
}

// Function to execute processes in Round Robin scheduling
void executeProcesses(vector<Process> &processes, int quantum, vector<int> &ganttOrder, vector<int> &completionTimes, int &currentTime, int &completed)
{
    bool anyProcessExecuted = false;
    for (Process &p : processes)
    {
        if (!p.completed && p.arrivalTime <= currentTime)
        {
            anyProcessExecuted = true;
            int timeSlice = min(quantum, p.remainingTime);

            // First execution time is the response time
            if (!p.firstExecution)
            {
                p.responseTime = currentTime - p.arrivalTime;
                p.firstExecution = true;
            }
            ganttOrder.push_back(p.id);
            currentTime += timeSlice;
            p.remainingTime -= timeSlice;

            if (p.remainingTime == 0)
            {
                p.turnAroundTime = currentTime - p.arrivalTime;
                p.waitingTime = p.turnAroundTime - p.burstTime;
                p.completed = true;
                completed++;
            }

            completionTimes.push_back(currentTime);
        }
    }

    if (!anyProcessExecuted)
    {
        currentTime++; // Increment time if no process was executed
    }
}

// Function to display waiting time, turn around time, and response time for each process in table format
void displayProcessTimes(const vector<Process> &processes)
{
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl;
    cout << "| Process | Arrival Time | Burst Time | Turn Around Time | Waiting Time | Response Time |" << endl;
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl;

    for (const Process &p : processes)
    {
        cout << "|   P" << setw(3) << left << p.id
             << "  |      " << setw(8) << left << p.arrivalTime
             << "|     " << setw(7) << left << p.burstTime
             << "|       " << setw(11) << left << p.turnAroundTime
             << "|      " << setw(8) << left << p.waitingTime
             << "|       " << setw(8) << left << p.responseTime << "|\n";
    }
    cout << "+---------+--------------+------------+------------------+--------------+---------------+" << endl
         << endl;
}

// Function to display the Gantt chart for Round Robin scheduling
void displayGanttChart(vector<Process> &processes, int quantum)
{
    int n = processes.size();
    int currentTime = 0, completed = 0;
    vector<int> ganttOrder;
    vector<int> completionTimes;

    // Initialize remaining time and first execution flag for each process
    for (int i = 0; i < n; i++)
    {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completed = false;
        processes[i].firstExecution = false;
    }

    while (completed < n)
    {
        executeProcesses(processes, quantum, ganttOrder, completionTimes, currentTime, completed);
    }

    // Display the Gantt chart
    cout << endl << "Gantt Chart: " << endl;

    cout << "+";
    for (size_t i = 0; i < ganttOrder.size(); i++)
        cout << "-------+";
    cout << endl << "|";

    for (int id : ganttOrder)
        cout << "  P" << id << "   |";
    cout << endl << "+";

    for (size_t i = 0; i < ganttOrder.size(); i++)
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
    int totalWaitingTime = 0, totalTurnAroundTime = 0, totalResponseTime = 0;
    int n = processes.size();
    for (const Process &p : processes)
    {
        totalWaitingTime += p.waitingTime;
        totalTurnAroundTime += p.turnAroundTime;
        totalResponseTime += p.responseTime;
    }
    cout << "Average Turn Around Time: " << (float)totalTurnAroundTime / n << endl;
    cout << "Average Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Response Time: " << (float)totalResponseTime / n << endl;
}

int main()
{
    cout << "\t\t==========================" << endl;
    cout << "\t\t  Round Robin Scheduling  " << endl;
    cout << "\t\t==========================" << endl;

    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> quantum;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    // Sort processes based on arrival time
    sort(processes.begin(), processes.end(), [](Process a, Process b) { return a.arrivalTime < b.arrivalTime; });

    // Display Gantt chart
    displayGanttChart(processes, quantum);

    // Display process information with waiting time, turn around time, and response time
    displayProcessTimes(processes);

    // Display average times
    calculateAverages(processes);

    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
