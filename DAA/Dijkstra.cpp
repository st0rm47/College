#include<iostream>
#include<climits>
#include<queue>
#include<vector>
using namespace std;

// Function to print the current distances from the source vertex
void printDistances(const vector<int>& dist) {
    cout << "Current distances: ";
    for (int d : dist) {
        if (d == INT_MAX) cout << "INF ";
        else cout << d << " ";
    }
    cout << endl;
    cout << "---------------------------------" << endl;
}

// Function to perform Dijkstra's algorithm
void dijkstra(int graph[100][100], int n, int source) 
{
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[source] = 0;

    // Priority queue to select the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    cout << endl << "Steps of Dijkstra's Algorithm:" << endl;
    cout << "---------------------------------" << endl;

    // Print initial distances
    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        cout << endl << "Processing vertex: " << u << endl;

        // Iterate through all vertices to update distances
        for (int v = 0; v < n; v++) 
        {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) 
            {
                cout << "Updating distance of vertex " << v << " from " 
                     << (dist[v] == INT_MAX ? "INF" : to_string(dist[v]))
                     << " to " << dist[u] + graph[u][v] << endl;
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }

        printDistances(dist);
    }

    cout << endl << "Final Result:" << endl;
    cout << "+--------+----------------------+" << endl;
    cout << "| Vertex | Distance from Source |" << endl;
    cout << "+--------+----------------------+" << endl;
    for (int i = 0; i < n; i++) 
    {
        printf("|   %-5d|        %-14d|\n", i, dist[i]);
    }
    cout << "+--------+----------------------+\n";
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
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> source;

    // Perform Dijkstra's algorithm
    dijkstra(graph, n, source);

    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
