#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Structure to represent a process
struct Process 
{
    int id;                 // Process ID
    int burstTime;          // Burst Time 
    int arrivalTime;        // Arrival Time
    int waitingTime;        // Waiting Time
    int turnAroundTime;     // Turn Around Time
    int responseTime;       // Response Time
};

// Function to calculate waiting time, turn around time, and response time for each process
void calculateTimes(vector<Process>& processes) 
{
    int n = processes.size();
    int currentTime = 0;  // Keep track of the current time

    // Calculate waiting time, turn around time, and response time
    for (int i = 0; i < n; i++) 
    {
        // Update current time to the process's arrival time if it's greater (i.e., CPU idle time)
        if (currentTime < processes[i].arrivalTime)
            currentTime = processes[i].arrivalTime;

        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].responseTime = processes[i].waitingTime;
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
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

// Function to display the Gantt chart
void displayGanttChart(const vector<Process> &processes)
{
    int currentTime = 0;
    cout << endl << "Gantt Chart: " << endl;

    cout << "+";
    for (const Process &p : processes)
        cout << "-------+";
    cout << endl << "|";
    for (const Process &p : processes)
    {
        if (currentTime < p.arrivalTime)
            currentTime = p.arrivalTime; // Adjust time for idle periods
        cout << "   P" << p.id << "  |";
        currentTime += p.burstTime;
    }
    cout << endl << "+";
    for (const Process &p : processes)
        cout << "-------+";
    cout << endl;
    currentTime = 0;
    cout << "0";
    for (const Process &p : processes)
    {
        if (currentTime < p.arrivalTime)
            currentTime = p.arrivalTime; // Adjust time for idle periods
        currentTime += p.burstTime;
        cout << setw(8) << currentTime;
    }
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
    cout << "\t\t===========================" << endl;
    cout << "\t\t  FCFS Process Scheduling  " << endl;
    cout << "\t\t===========================" << endl;

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

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
