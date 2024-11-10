#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate total seek time
int calculateSeekTime(const vector<int> &requests, int headPosition)
{
    int totalSeekTime = 0;
    int currentPosition = headPosition;
    for (int request : requests)
    {
        int seekTime = abs(currentPosition - request);
        totalSeekTime += seekTime;
        currentPosition = request;
    }
    return totalSeekTime;
}

int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  FCFS Disk Scheduling  " << endl;
    cout << "\t\t========================" << endl;

    int n, headPosition, diskSize;

    cout << "Enter the disk size: ";
    cin >> diskSize;

    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> requests[i];
        if (requests[i] < 0 || requests[i] >= diskSize)
        {
            cout << "Request " << requests[i] << " is out of disk bounds. Please enter a value between 0 and " << diskSize - 1 << "." << endl;
            --i;
        }
    }

    cout << "Enter the initial head position: ";
    cin >> headPosition;
    if (headPosition < 0 || headPosition >= diskSize)
    {
        cout << "Head position out of disk bounds. Please enter a value between 0 and " << diskSize - 1 << "." << endl;
        return 1;
    }

    int totalSeekTime = calculateSeekTime(requests, headPosition);
    cout << "Total seek time: " << totalSeekTime << " tracks" << endl;

    cout << endl << "Compiled by: Subodh Ghimire" << endl;
    return 0;
}