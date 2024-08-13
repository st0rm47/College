#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int fifoPageReplacement(const vector<int> &page_references, int frame_size)
{
    queue<int> frames;
    vector<int> frame_content(frame_size, -1);
    int page_faults = 0;

    // Print the table header
    cout << "+----------------+---------+---------+---------+------------+" << endl;
    cout << "| Page Reference | Frame 1 | Frame 2 | Frame 3 | Page Fault |" << endl;
    cout << "+----------------+---------+---------+---------+------------+" << endl;

    for (int page : page_references)
    {
        bool page_fault_occurred = false;

        // Check if the page is already in frames
        auto it = find(frame_content.begin(), frame_content.end(), page);
        if (it == frame_content.end())
        {
            // Page fault occurs
            if (frames.size() < frame_size)
            {
                frames.push(page);
                frame_content[frames.size() - 1] = page;
            }
            else
            {
                int old_page = frames.front();
                frames.pop();
                frames.push(page);
                replace(frame_content.begin(), frame_content.end(), old_page, page);
            }
            page_faults++;
            page_fault_occurred = true;
        }

        // Display the current frame status
        cout << "| " << setw(10) << page << "     |";
        for (int i = 0; i < frame_size; i++)
        {
            if (i < frames.size())
                cout << setw(5) << frame_content[i] << "    |";
            else
                cout << setw(5) << " " << "    |";
        }
        cout << setw(10) << (page_fault_occurred ? "Yes" : "No") << "  |" << endl;
        cout << "+----------------+---------+---------+---------+------------+" << endl;
    }
    return page_faults;
}

int main()
{
    cout << "\t\t=========================" << endl;
    cout << "\t\t  FIFO Page Replacement  " << endl;
    cout << "\t\t=========================" << endl;

    int n, frame_size;
    cout << "Enter the number of pages: ";
    cin >> n;

    vector<int> page_references(n);
    cout << "Enter the page references: ";
    for (int &page : page_references)
        cin >> page;
    cout << "Enter the frame size: ";
    cin >> frame_size;

    int page_faults = fifoPageReplacement(page_references, frame_size);
    cout << endl << "Total number of page faults: " << page_faults << endl;
    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
