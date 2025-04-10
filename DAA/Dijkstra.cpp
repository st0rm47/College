#include<iostream>
#include<climits>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

// Function to convert vertex index to alphabet
string vertexName(int index) {
    return string(1, 'A' + index);
}

// Function to print the current distances from the source vertex
void printDistances(const vector<int>& dist) {
    cout << "Current distances: ";
    for (int d : dist) {
        if (d == INT_MAX) cout << "INF ";
        else cout << d << " ";
    }
    cout << endl << "---------------------------------" << endl;
}

// Function to reconstruct and return the path from source to a vertex
string getPath(int vertex, const vector<int>& parent) {
    if (vertex == -1) return "";
    string path = getPath(parent[vertex], parent);
    return path.empty() ? vertexName(vertex) : path + "," + vertexName(vertex);
}

// Dijkstra's Algorithm
void dijkstra(int graph[100][100], int n, int source) 
{
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    dist[source] = 0;

    // Min-priority queue: {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    cout << endl << "Steps of Dijkstra's Algorithm:" << endl;
    cout << "---------------------------------" << endl;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        cout << endl << "Processing vertex: " << vertexName(u) << endl;

        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) 
            {
                cout << "Updating distance of vertex " << vertexName(v) << " from " 
                     << (dist[v] == INT_MAX ? "INF" : to_string(dist[v]))
                     << " to " << dist[u] + graph[u][v] << endl;
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
        printDistances(dist);
    }

    // Final Tabular Output
    cout << "\nFinal Result:\n";
    cout << "+---------+----------------------+----------------+\n";
    cout << "| Vertex  | Distance from Source | Path           |\n";
    cout << "+---------+----------------------+----------------+\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "|   " << setw(3) << vertexName(i)
             << "   |        " << setw(5) << (dist[i] == INT_MAX ? "INF" : to_string(dist[i]))
             << "         |  ";
        if (dist[i] == INT_MAX)
            cout << "No Path";
        else
            cout << getPath(i, parent);
        cout << setw(16 - getPath(i, parent).length()) << " |\n";
    }
    cout << "+---------+----------------------+----------------+\n";
}

int main() 
{
    cout << "\t\t========================" << endl;
    cout << "\t\t  Dijkstra's Algorithm  " << endl;
    cout << "\t\t========================" << endl;

    int n, source;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix (0 for no edge):" << endl;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            cin >> graph[i][j];

    cout << "Enter the source vertex index (0 for A, 1 for B, ...): ";
    cin >> source;

    // Perform Dijkstra's algorithm
    dijkstra(graph, n, source);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
