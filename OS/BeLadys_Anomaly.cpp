#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int fifoPageReplacement(const vector<int> &pages, int frame_size) 
{
    queue<int> frames;
    vector<int> frame_content(frame_size, -1);  
    int pageFaults = 0;

    // Print the table header
    cout << endl << " Frame Size: " << frame_size << endl;
    cout << "+----------------+";
    for (int i = 0; i < frame_size; i++) cout << "---------+";
    cout << "------------+" << endl;
    cout << "| Page Reference |";
    for (int i = 0; i < frame_size; i++) cout << " Frame " << i + 1 << " |";
    cout << " Page Fault |" << endl;
    cout << "+----------------+";
    for (int i = 0; i < frame_size; i++) cout << "---------+";
    cout << "------------+" << endl;

    for (int page : pages)
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
            pageFaults++;
            page_fault_occurred = true;
        }

        // Print the current state of frames
        cout << "| " << setw(8) << page << "       |"; 
        for (int i = 0; i < frame_size; i++) 
        {
            if (i < frames.size())
                cout << setw(5) << frame_content[i] << "    |";
            else
                cout << setw(5) << " " << "    |";
        }
        cout << setw(8) << (page_fault_occurred ? "Yes" : "No") << "    |" << endl;
        cout << "+----------------+";
        for (int i = 0; i < frame_size; i++) cout << "---------+";
        cout << "------------+" << endl;
    }
    return pageFaults;
}

int main() 
{
    cout << "\t\t===========================" << endl;
    cout << "\t\t  Belady's Anomaly (FIFO)  " << endl;
    cout << "\t\t===========================" << endl;

    int n, frame_size;
    cout << "Enter the number of pages: ";
    cin >> n;

    vector<int> page_references(n);
    cout << "Enter the page references: ";
    for (int &page : page_references)
        cin >> page;

    // Run simulation for frame size 3
    int pageFaults3 = fifoPageReplacement(page_references, 3);
    cout << "Total Page Faults with 3 Frames: " << pageFaults3 << endl;

    // Run simulation for frame size 4
    int pageFaults4 = fifoPageReplacement(page_references, 4);
    cout << "Total Page Faults with 4 Frames: " << pageFaults4 << endl;

    if (pageFaults4 > pageFaults3)
        cout << endl << "Belady's Anomaly Detected: More frames resulted in more page faults!" << endl;
    else 
        cout << endl << "No Belady's Anomaly: More frames resulted in fewer or equal page faults." << endl;
    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
