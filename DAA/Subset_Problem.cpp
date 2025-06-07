#include <iostream>
#include <vector>
using namespace std;

void printSubset(const vector<int> &subset) {
    cout << "{ ";
    for (int num : subset)
        cout << num << " ";
    cout << "}";
}

// Recursive Backtracking Function
void subsetSumBacktrack(vector<int> &arr, int index, int target, vector<int> &current, int currentSum) {
    if (currentSum == target) {
        printSubset(current);
        cout << endl;
        return;
    }

    if (index >= arr.size() || currentSum > target)
        return;

    // Include current element
    current.push_back(arr[index]);
    subsetSumBacktrack(arr, index + 1, target, current, currentSum + arr[index]);

    // Exclude current element (backtrack)
    current.pop_back();
    subsetSumBacktrack(arr, index + 1, target, current, currentSum);
}

int main() {
    cout << "\t\t=====================================" << endl;
    cout << "\t\t  Subset Sum Problem (Backtracking)  " << endl;
    cout << "\t\t=====================================" << endl;

    int n, target;
    cout << "\nEnter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the target sum: ";
    cin >> target;

    cout << "\nSubsets with sum = " << target << " are:\n";
    vector<int> current;
    subsetSumBacktrack(arr, 0, target, current, 0);

    cout << "\nCompiled by : Subodh Ghimire\n";
    return 0;
}
