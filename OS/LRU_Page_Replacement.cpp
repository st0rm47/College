#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>

using namespace std;

int lruPageReplacement(const vector<int> &page_references, int frame_size) {
    deque<int> frames;    // Use deque to manage LRU efficiently
    vector<int> frame_content(frame_size, -1); // To keep track of frame contents
    int page_faults = 0;

    // Print the table header
    cout << "+----------------+---------+---------+---------+------------+" << endl;
    cout << "| Page Reference | Frame 1 | Frame 2 | Frame 3 | Page Fault |" << endl;
    cout << "+----------------+---------+---------+---------+------------+" << endl;

    for (int page : page_references) {
        bool page_fault_occurred = false;
        auto it = find(frames.begin(), frames.end(), page);

        if (it == frames.end()) {
            // Page fault occurs
            if (frames.size() >= frame_size) {
                // Remove the least recently used page
                int lru_page = frames.front();
                frames.pop_front();
                // Update the frame content
                auto frame_it = find(frame_content.begin(), frame_content.end(), lru_page);
                if (frame_it != frame_content.end()) {
                    *frame_it = -1; // Mark as empty
                }
            }
            frames.push_back(page);
            // Update the frame content
            auto empty_it = find(frame_content.begin(), frame_content.end(), -1);
            if (empty_it != frame_content.end()) {
                *empty_it = page;
            }
            page_faults++;
            page_fault_occurred = true;
        } else {
            // Page is already in the frame, move it to the back
            frames.erase(it);
            frames.push_back(page);
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

int main() {
    cout << "\t\t=========================" << endl;
    cout << "\t\t  LRU Page Replacement  " << endl;
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
    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
