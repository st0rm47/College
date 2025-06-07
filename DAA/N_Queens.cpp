#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int solutionCount = 0;

// Function to check if placing queen is safe
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check left upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check right upper diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Function to print the board
void printBoard(const vector<vector<int>> &board, int n) {
    solutionCount++;
    cout << "\nSolution #" << solutionCount << ":\n";
    
    // Column headers
    cout << "+";
    for (int i = 0; i < n; i++)
        cout << "------";
    cout << "+\n";

    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            if (board[i][j])
                cout << setw(5) << "Q" << " ";
            else
                cout << setw(5) << "." << " ";
        }
        cout << "|\n";

        // Row separator
        cout << "+";
        for (int j = 0; j < n; j++)
            cout << "------";
        cout << "+\n";
    }
}

// Backtracking function
void solveNQueens(vector<vector<int>> &board, int row, int n) {
    if (row == n) {
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, n);
            board[row][col] = 0; // backtrack
        }
    }
}

int main() {
    cout << "\t\t====================" << endl;
    cout << "\t\t  N-Queens Problem  " << endl;
    cout << "\t\t====================" << endl;

    int n;
    cout << "\nEnter the number of queens (N): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solveNQueens(board, 0, n);

    if (solutionCount == 0)
        cout << "\nNo solution exists for N = " << n << "." << endl;
    else
        cout << "\nTotal solutions found: " << solutionCount << endl;

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
