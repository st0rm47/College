#include <iostream>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// Function to print optimal parenthesis
void printParenthesis(int i, int j, vector<vector<int>> &bracket, char &name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}

// Matrix Chain Multiplication using DP
void matrixChainOrder(vector<int> &dims)
{
    int n = dims.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    // Cost is zero when multiplying one matrix
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    // Display DP Table
    cout << "\nMatrix Chain Multiplication Table:" << endl;
    cout << "\n+----------------------------------+" << endl;
    cout << "|      ";
    for (int j = 0; j < n; j++)
        cout << "| " << setw(3) << (char)('A' + j) << "  ";
    cout << "|" << endl;


    cout << "+------";
    for (int j = 0; j < n; j++)
        cout << "+------";
    cout << "+" << endl;

    // Matrix rows
    for (int i = 0; i < n; i++) {
        cout << "|  " << (char)('A' + i) << "   ";
        for (int j = 0; j < n; j++) {
            cout << "|";
            if (j < i)
                cout << "      ";
            else if (i == j)
                cout << setw(6) << "0";
            else
                cout << setw(6) << m[i][j];
        }
        cout << "|" << endl;

        // Row separator
        cout << "+------";
        for (int j = 0; j < n; j++)
            cout << "+------";
        cout << "+" << endl;
    }
    
    cout << "\nMinimum number of scalar multiplications: " << m[0][n - 1] << endl;

    cout << "Optimal parenthesization: ";
    char name = 'A';
    printParenthesis(0, n - 1, bracket, name);
    cout << endl;
}

int main()
{
    cout << "\t\t===============================" << endl;
    cout << "\t\t  Matrix Chain Multiplication  " << endl;
    cout << "\t\t===============================" << endl;

    int n;
    cout << "\nEnter the number of matrices: ";
    cin >> n;

    vector<int> dims(n + 1);
    cout << "\nEnter the dimensions (P0 P1 P2 ... Pn): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> dims[i];
    }

    cout << "\nDimensions of matrices:" << endl;
    cout << "+--------+------------+" << endl;
    cout << "| Matrix | Dimensions |" << endl;
    cout << "+--------+------------+" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|    " << (char)('A' + i) << "   | " << setw(3) << dims[i] << " x " << setw(3) << dims[i + 1] << "  |" << endl;
    }
    cout << "+--------+------------+" << endl;

    matrixChainOrder(dims);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
