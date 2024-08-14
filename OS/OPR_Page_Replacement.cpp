#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int optimalPageReplacement(const vector<int> &page_references, int frame_size)
{
    vector<int> frames(frame_size, -1); // Use a vector to manage frames
    int page_faults = 0;

    // Print the table header
    cout << "+----------------+---------+---------+---------+------------+" << endl;
    cout << "| Page Reference | Frame 1 | Frame 2 | Frame 3 | Page Fault |" << endl;
    cout << "+----------------+---------+---------+---------+------------+" << endl;

    for (int i = 0; i < page_references.size(); ++i)
    {
        int page = page_references[i];
        bool page_fault_occurred = false;
        auto it = find(frames.begin(), frames.end(), page);

        if (it == frames.end())
        {
            // Page fault occurs
            page_fault_occurred = true;
            page_faults++;

            // Check if there is a free frame
            if (find(frames.begin(), frames.end(), -1) != frames.end())
            {
                *find(frames.begin(), frames.end(), -1) = page;
            }
            else
            {
                // Find the frame that will not be used for the longest time in the future
                int farthest = i, replace_index = 0;
                for (int j = 0; j < frame_size; ++j)
                {
                    int k;
                    for (k = i + 1; k < page_references.size(); ++k)
                    {
                        if (frames[j] == page_references[k])
                        {
                            if (k > farthest)
                            {
                                farthest = k;
                                replace_index = j;
                            }
                            break;
                        }
                    }
                    if (k == page_references.size())
                    { // Not found in the future
                        replace_index = j;
                        break;
                    }
                }
                frames[replace_index] = page;
            }
        }

        // Display the current frame status
        cout << "| " << setw(10) << page << "     |";
        for (int j = 0; j < frame_size; j++)
        {
            if (frames[j] != -1)
                cout << setw(5) << frames[j] << "    |";
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
    cout << "\t\t========================" << endl;
    cout << "\t\t  OPR Page Replacement  " << endl;
    cout << "\t\t========================" << endl;

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
    cout << endl << "Compiled by : Subodh Ghimire " << endl;
    return 0;
}
