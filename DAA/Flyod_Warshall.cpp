#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define INF 99999

void displayDistanceMatrix(const vector<vector<int>> &dist, int V) {
    cout << "\nAll-Pairs Shortest Path Matrix (Floyd-Warshall):" << endl;
    cout << "\n+---------------------------+" << endl;
    cout << "|      ";
    for (int j = 0; j < V; j++)
        cout << "| " << setw(3) << (char)('A' + j) << "  ";
    cout << "|" << endl;

    cout << "+------";
    for (int j = 0; j < V; j++)
        cout << "+------";
    cout << "+" << endl;

    for (int i = 0; i < V; i++) {
        cout << "|  " << (char)('A' + i) << "   ";
        for (int j = 0; j < V; j++) {
            cout << "|";
            if (dist[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << dist[i][j];
        }
        cout << "|" << endl;

        cout << "+------";
        for (int j = 0; j < V; j++)
            cout << "+------";
        cout << "+" << endl;
    }
}

// Floyd-Warshall Algorithm to find all pairs shortest paths
void floydWarshall(vector<vector<int>> graph, int V) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    displayDistanceMatrix(dist, V);
}

int main() {
    cout << "\t\t============================" << endl;
    cout << "\t\t  Floyd-Warshall Algorithm  " << endl;
    cout << "\t\t============================" << endl;

    int V;
    cout << "\nEnter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "\nEnter the adjacency matrix (use " << INF << " for INF):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
