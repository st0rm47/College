#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Structure to store segment information
struct Segment
{
    int base;
    int limit;
};

// Function to calculate physical address
int calculatePhysicalAddress(const Segment &seg, int logicalAddress)
{
    if (logicalAddress >= 0 && logicalAddress < seg.limit)
        return seg.base + logicalAddress;
    else
        return -1;
}

int main()
{
    cout << "\t\t======================" << endl;
    cout << "\t\t  Segmentation Table  " << endl;
    cout << "\t\t======================" << endl;

    int numSegments;
    cout << "Enter the number of segments: ";
    cin >> numSegments;

    vector<Segment> segments(numSegments);
    int logicalAddress; 
    
    // Input base limit and logical address for each segment
    for (int i = 0; i < numSegments; ++i)
    {
        cout << endl << "Enter base limit and logical address for segment " << i << ":\n";
        cout << "Base: ";
        cin >> segments[i].base;
        cout << "Limit: ";
        cin >> segments[i].limit;
        cout << "Logical Address: ";
        cin >> logicalAddress;
    }

    // Display segment table with headers and formatted rows
    cout << "+-----------+-------+--------+-------------------+" << endl;
    cout << "| Segment # | Base  | Limit  | Physical Address  |" << endl;
    cout << "+-----------+-------+--------+-------------------+" << endl;

    for (int i = 0; i < numSegments; ++i)
    {
        int physicalAddress = calculatePhysicalAddress(segments[i], logicalAddress);
        cout << "| " << setw(9) << i
             << " | " << setw(5) << segments[i].base
             << " | " << setw(6) << segments[i].limit
             << " | " << setw(17);

        if (physicalAddress != -1)
            cout << physicalAddress;
        else
            cout << "Out of Bounds";
        cout << " |" << endl;
    }
    cout << "+-----------+-------+--------+-------------------+" << endl;

    cout << "\nCompiled by: Subodh Ghimire" << endl;
    return 0;
}
