#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to calculate total seek time using SCAN algorithm
int calculateSeekTimeSCAN(vector<int> &requests, int headPosition, string direction, int diskSize)
{
    int totalSeekTime = 0;
    vector<int> left, right;

    // Separate requests into those left and right of the head
    for (int request : requests)
    {
        if (request < headPosition)
            left.push_back(request);
        else
            right.push_back(request);
    }

    // Add disk boundaries to simulate the end of disk for SCAN
    if (direction == "left")
        left.push_back(0);
    else
        right.push_back(diskSize - 1);

    // Sort left and right requests
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    // Process requests in the SCAN order
    if (direction == "left")
    {
        // Move left first, then reverse to right
        for (int i = left.size() - 1; i >= 0; i--)
        {
            totalSeekTime += abs(headPosition - left[i]);
            headPosition = left[i];
        }
        for (int i = 0; i < right.size(); i++)
        {
            totalSeekTime += abs(headPosition - right[i]);
            headPosition = right[i];
        }
    }
    else
    {
        // Move right first, then reverse to left
        for (int i = 0; i < right.size(); i++)
        {
            totalSeekTime += abs(headPosition - right[i]);
            headPosition = right[i];
        }
        for (int i = left.size() - 1; i >= 0; i--)
        {
            totalSeekTime += abs(headPosition - left[i]);
            headPosition = left[i];
        }
    }
    return totalSeekTime;
}

int main()
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  SCAN Disk Scheduling  " << endl;
    cout << "\t\t========================" << endl;

    int n, headPosition, diskSize;
    string direction;

    cout << "Enter the disk size: ";
    cin >> diskSize;

    cout << "Enter the number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> requests[i];
        if (requests[i] < 0 || requests[i] >= diskSize)
        {
            cout << "Request " << requests[i] << " is out of disk bounds." << endl;
            i--; 
        }
    }
    cout << "Enter the initial head position: ";
    cin >> headPosition;
    if (headPosition < 0 || headPosition >= diskSize)
    {
        cout << "Head position out of disk bounds." << endl;
        return 1; 
    }

    cout << "Enter the initial direction (left/right): ";
    cin >> direction;

    int totalSeekTime = calculateSeekTimeSCAN(requests, headPosition, direction, diskSize);
    cout << "Total seek time: " << totalSeekTime << " tracks" << endl;

    cout << endl << "Compiled by: Subodh Ghimire" << endl;
    return 0;
}
