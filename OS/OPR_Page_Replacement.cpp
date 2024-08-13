#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int optimalPageReplacement(const vector<int> &page_references, int frame_size) {
    vector<int> frames(frame_size, -1);  // Stores the page numbers in frames
    int page_faults = 0;

    // Print the table header
    cout << "+-----------------+----------+----------+----------+---------------+" << endl;
    cout << "| Page Reference  | Frame 1  | Frame 2  | Frame 3  | Page Fault    |" << endl;
    cout << "+-----------------+----------+----------+----------+---------------+" << endl;

    for (int current_index = 0; current_index < page_references.size(); ++current_index) {
        int page = page_references[current_index];
        bool page_fault_occurred = false;
        bool page_in_frames = false;

        // Check if the page is already in frames
        for (int i = 0; i < frame_size; ++i) {
            if (frames[i] == page) {
                page_in_frames = true;
                break;
            }
        }

        if (!page_in_frames) {
            // Page fault occurs
            if (find(frames.begin(), frames.end(), -1) != frames.end()) {
                // Empty frame available
                for (int i = 0; i < frame_size; ++i) {
                    if (frames[i] == -1) {
                        frames[i] = page;
                        break;
                    }
                }
            } else {
                // Find the page to replace
                vector<int> future_use(frame_size, -1);
                for (int i = 0; i < frame_size; ++i) {
                    for (int j = current_index + 1; j < page_references.size(); ++j) {
                        if (frames[i] == page_references[j]) {
                            future_use[i] = j;
                            break;
                        }
                    }
                }
                // Find the page that will not be used for the longest time
                int replace_index = 0;
                for (int i = 1; i < frame_size; ++i) {
                    if (future_use[i] == -1) {
                        replace_index = i;
                        break;
                    }
                    if (future_use[i] > future_use[replace_index]) {
                        replace_index = i;
                    }
                }
                frames[replace_index] = page;
            }
            page_faults++;
            page_fault_occurred = true;
        }

        // Display the current frame status
        cout << "| " << setw(15) << page << " |";
        for (int i = 0; i < frame_size; ++i) {
            cout << setw(8) << frames[i] << "  |";
        }
        cout << setw(11) << (page_fault_occurred ? "Yes" : "No") << "    |" << endl;
        cout << "+-----------------+----------+----------+----------+---------------+" << endl;
    }

    return page_faults;
}

int main() {
    cout << "\t\t=========================" << endl;
    cout << "\t\t Optimal Page Replacement " << endl;
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

    int page_faults = optimalPageReplacement(page_references, frame_size);
    cout << endl << "Total number of page faults: " << page_faults << endl;
    return 0;
}
