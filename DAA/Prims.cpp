#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge 
{
    int to, weight;
};

// Function to perform Prim's Algorithm
void prim(int V, vector<vector<Edge>>& graph) 
{
    int step = 1;
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);

    key[0] = 0;

    cout << "Step " << step++ << ": Initialize all keys to INF except the first vertex." << endl;

    for (int count = 0; count < V - 1; ++count) 
    {
        // Pick the minimum key vertex not yet included in MST
        int u = -1;
        for (int i = 0; i < V; ++i) 
        {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) 
            {
                u = i;
            }
        }

        inMST[u] = true;
        cout << "Step " << step++ << ": Include vertex " << u << " in MST." << endl;

        // Update the keys and parent for adjacent vertices
        for (auto& edge : graph[u]) 
        {
            int v = edge.to;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v]) 
            {
                key[v] = weight;
                parent[v] = u;
                cout << "Updated: parent[" << v << "] = " << u << ", key[" << v << "] = " << weight << endl;
            }
        }
    }

    int totalCost = 0;
    cout << endl << "Minimum Spanning Tree (MST):" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "| Starting Vertex | Ending Vertex | Weight |" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 1; i < V; ++i) {
        cout << "| " << setw(8) << parent[i] << setw(10)
             << " | " << setw(8) << i << setw(8)
             << " | " << setw(3) << key[i] << setw(5) << " |" << endl;
        totalCost += key[i];
    }
    cout << "--------------------------------------------" << endl;
    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    cout << "\t\t====================" << endl;
    cout << "\t\t  Prim's Algorithm  " << endl;
    cout << "\t\t====================" << endl;

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<Edge>> graph(V);
    cout << "Enter edges (Starting Vertex, Ending Vertex, Weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // because the graph is undirected
    }
    cout << endl;

    // Perform Prim's Algorithm
    prim(V, graph);

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}
