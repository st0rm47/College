#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to sort the requests in ascending order
void Sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to calculate total seek time using C-LOOK algorithm
int calculateSeekTimeCLOOK(vector<int> &requests, int headPosition, int diskSize)
{
    int totalSeekTime = 0;
    vector<int> left, right;

    // Separate requests into those left and right of the head
    for (int request : requests)
    {
        if (request > headPosition)
            right.push_back(request);
        else
            left.push_back(request);
    }
    Sort(left);
    Sort(right);

    // Process requests in the C-LOOK order
    // Move towards the end in the right direction, then wrap to the leftmost request
    for (int i = 0; i < right.size(); i++)
    {
        totalSeekTime += abs(headPosition - right[i]);
        headPosition = right[i];
    }

    // Jump back to the leftmost request (wrap around)
    if (!left.empty())
    {
        totalSeekTime += abs(headPosition - left[0]);
        headPosition = left[0];
    }

    // Service the remaining requests on the left side
    for (int i = 0; i < left.size(); i++)
    {
        totalSeekTime += abs(headPosition - left[i]);
        headPosition = left[i];
    }
    return totalSeekTime;
}

int main()
{
    cout << "\t\t==========================" << endl;
    cout << "\t\t  C-LOOK Disk Scheduling  " << endl;
    cout << "\t\t==========================" << endl;

    int n, headPosition, diskSize;
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

    int totalSeekTime = calculateSeekTimeCLOOK(requests, headPosition, diskSize);
    cout << "Total seek time: " << totalSeekTime << " tracks" << endl;

    cout << endl << "Compiled by: Subodh Ghimire" << endl;
    return 0;
}
