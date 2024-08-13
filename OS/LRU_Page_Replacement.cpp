#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int lruPageReplacement(const vector<int> &page_references, int frame_size) {
    queue<int> frames;  // Holds the current frames (order of use)
    vector<int> frame_content(frame_size, -1);  // Stores the page numbers in frames
    int page_faults = 0;

    // Print the table header
    cout << "+-----------------+----------+----------+----------+---------------+" << endl;
    cout << "| Page Reference  | Frame 1  | Frame 2  | Frame 3  | Page Fault    |" << endl;
    cout << "+-----------------+----------+----------+----------+---------------+" << endl;

    for (int page : page_references) {
        bool page_fault_occurred = false;
        bool page_in_frames = false;

        // Check if the page is already in frames
        for (int i = 0; i < frame_size; i++) {
            if (frame_content[i] == page) {
                page_in_frames = true;
                break;
            }
        }

        if (!page_in_frames) {
            // Page fault occurs
            if (frames.size() < frame_size) {
                frames.push(page);
                frame_content[frames.size() - 1] = page;
            } else {
                // Remove the least recently used page
                int lru_page = frames.front();
                frames.pop();
                // Replace it with the new page
                frames.push(page);
                // Update the frame content
                auto it = find(frame_content.begin(), frame_content.end(), lru_page);
                if (it != frame_content.end()) {
                    *it = page;
                }
            }
            page_faults++;
            page_fault_occurred = true;
        }

        // Display the current frame status
        cout << "| " << setw(15) << page << " |";
        for (int i = 0; i < frame_size; i++) {
            if (i < frames.size())
                cout << setw(8) << frame_content[i] << "  |";
            else
                cout << setw(8) << " " << "  |";
        }
        cout << setw(11) << (page_fault_occurred ? "Yes" : "No") << "    |" << endl;
        cout << "+-----------------+----------+----------+----------+---------------+" << endl;
    }
    return page_faults;
}

int main() {
    cout << "\t\t=========================" << endl;
    cout << "\t\t    LRU Page Replacement  " << endl;
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

    int page_faults = lruPageReplacement(page_references, frame_size);
    cout << endl << "Total number of page faults: " << page_faults << endl;
    return 0;
}
