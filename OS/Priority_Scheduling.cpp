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
    int priority;        // Priority
    bool completed;      // Flag to check if the process is completed
};

// Function to find the highest priority process that has arrived
int findHighestPriorityProcess(const vector<Process>& processes, int currentTime) 
{
    int idx = -1;
    int maxPriority = INT_MAX;

    for (int i = 0; i < processes.size(); i++) 
    {
        if (!processes[i].completed && processes[i].arrivalTime <= currentTime) 
        {
            if (processes[i].priority < maxPriority || 
                (processes[i].priority == maxPriority && processes[i].arrivalTime < processes[idx].arrivalTime)) 
            {
                maxPriority = processes[i].priority;
                idx = i;
            }
        }
    }
    return idx;
}

// Function to calculate waiting time, turn around time, and response time for each process
void calculateTimes(vector<Process>& processes) 
{
    int n = processes.size();
    int currentTime = 0, completed = 0;

    while (completed < n) 
    {
        int idx = findHighestPriorityProcess(processes, currentTime);

        if (idx != -1) 
        {
            processes[idx].waitingTime = currentTime - processes[idx].arrivalTime;
            processes[idx].responseTime = processes[idx].waitingTime;
            processes[idx].turnAroundTime = processes[idx].waitingTime + processes[idx].burstTime;
            currentTime += processes[idx].burstTime;
            processes[idx].completed = true;
            completed++;
        } 
        else 
        {
            currentTime++;
        }
    }
}

// Function to display the Gantt chart
void displayGanttChart(vector<Process> processes) 
{
    int n = processes.size();
    int currentTime = 0, completed = 0;
    vector<int> ganttOrder;
    vector<int> completionTimes(n, 0);

    while (completed < n) 
    {
        int idx = findHighestPriorityProcess(processes, currentTime);

        // If a process is found, execute it
        if (idx != -1) 
        {
            ganttOrder.push_back(processes[idx].id);
            currentTime += processes[idx].burstTime;
            completionTimes[ganttOrder.size() - 1] = currentTime;
            processes[idx].completed = true;
            completed++;
        } 
        else 
        {
            currentTime++;
        }
    }

    // Display the Gantt chart
    cout << endl << "Gantt Chart: " << endl;
    cout << "+";
    for (int i = 0; i < ganttOrder.size(); i++)
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

// Function to display waiting time, turn around time, and response time for each process
void displayProcessTimes(const vector<Process>& processes) 
{
    cout << "+---------+--------------+------------+----------+------------------+--------------+---------------+" << endl;
    cout << "| Process | Arrival Time | Burst Time | Priority | Turn Around Time | Waiting Time | Response Time |" << endl;
    cout << "+---------+--------------+------------+----------+------------------+--------------+---------------+" << endl;

    for (const Process& p : processes) 
    {
        cout << "|   P" << setw(3) << left << p.id
             << "  |      " << setw(8) << left << p.arrivalTime
             << "|     " << setw(7) << left << p.burstTime
             << "|    " << setw(6) << left << p.priority
             << "|       " << setw(11) << left << p.turnAroundTime
             << "|      " << setw(8) << left << p.waitingTime
             << "|       " << setw(8) << left << p.responseTime << "|\n";
    }
    cout << "+---------+--------------+------------+----------+------------------+--------------+---------------+" << endl << endl;
}

// Function to calculate average waiting time, turn around time, and response time
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
    cout << "\t\t============================" << endl;
    cout << "\t\t  Priority Process Scheduling  " << endl;
    cout << "\t\t============================" << endl;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) 
    {
        processes[i].id = i + 1;
        cout << "Enter Arrival Time, Burst Time, and Priority for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
        processes[i].completed = false;
    }

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
