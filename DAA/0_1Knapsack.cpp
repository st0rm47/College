#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to solve 0/1 Knapsack using DP
int knapsackDP(int capacity, const vector<int> &weights, const vector<int> &profits, int n, vector<vector<int>> &dp) {
    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

// Function to print the DP table
void printDPTable(const vector<vector<int>> &dp, int n, int capacity) {
    cout << "\nKnapsack DP Table:\n";

    // Top header separator
    cout << "+--------";
    for (int w = 0; w <= capacity; w++)
        cout << "+--------";
    cout << "+" << endl;

    // Column headers
    cout << "| Item\\W ";
    for (int w = 0; w <= capacity; w++)
        cout << "| " << setw(5) << w << "  ";
    cout << "|" << endl;

    // Mid separator
    cout << "+--------";
    for (int w = 0; w <= capacity; w++)
        cout << "+--------";
    cout << "+" << endl;

    // Data rows
    for (int i = 0; i <= n; i++) {
        cout << "|   " << setw(2) << i << "   ";
        for (int w = 0; w <= capacity; w++) {
            cout << "| " << setw(7) << dp[i][w];
        }
        cout << "|" << endl;

        cout << "+--------";
        for (int w = 0; w <= capacity; w++)
            cout << "+--------";
        cout << "+" << endl;
    }
}

int main() {
    cout << "\t\t============================" << endl;
    cout << "\t\t  0/1 Knapsack (DP Method)  " << endl;
    cout << "\t\t============================" << endl;

    int n, capacity;
    cout << "\nEnter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weights(n), profits(n);
    cout << "\nEnter weights of items and their profits :" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weights[i];
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> profits[i];
    }

    // Display item table
    cout << "\n+--------+--------+--------+" << endl;
    cout << "| Items  | Weight | Profit |" << endl;
    cout << "+--------+--------+--------+" << endl;
    for (int i = 0; i < n; i++) {
        cout << "|   " << setw(2) << i + 1 << "   | " << setw(6) << weights[i]
             << " | " << setw(6) << profits[i] << " |" << endl;
    }
    cout << "+--------+--------+--------+" << endl;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    int maxProfit = knapsackDP(capacity, weights, profits, n, dp);

    printDPTable(dp, n, capacity);

    // Backtracking to find selected items
    cout << "\nMaximum Profit: " << maxProfit << endl;
    cout << "Items selected: ";
    int w = capacity;
    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit != dp[i - 1][w]) {
            cout << i << " ";
            maxProfit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
    cout << endl;

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
