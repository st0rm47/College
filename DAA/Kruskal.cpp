#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // For std::setw
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight; 
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function for DSU (Disjoint Set Union)
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Union function for DSU 
void unionSet(int parent[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    parent[yroot] = xroot;
}

// Function to perform Kruskal's Algorithm
void kruskal(int V, vector<Edge>& edges) 
{
    int step = 1;
    int totalCost = 0;
    vector<Edge> mst;

    // Step 1: Sort the edges
    cout << "Step " << step++ << ": Sorting edges by weight\n";
    sort(edges.begin(), edges.end(), compare);

    cout << "Sorted Edges:\n";
    cout << "---------------------------------------------------" << endl;
    cout << "| Edge | Starting Vertex | Ending Vertex | Weight |" << endl;
    cout << "---------------------------------------------------" << endl;
    for (auto& e : edges) 
    {
        cout << "|  " << e.u << "-" << e.v << setw(3) 
             << " | " << setw(8) << e.u << setw(10)
             << " | " << setw(8) << e.v << setw(8)
             << " | " << setw(4) << e.weight << setw(4) << " |" << endl;
    }
    cout << "---------------------------------------------------" << endl;

    // Initialize parent for DSU
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Step 2: Kruskal's main loop
    cout << endl <<  "Step " << step++ << ": Selecting edges for MST" << endl;
    for (auto& e : edges) {
        int setU = find(parent, e.u);
        int setV = find(parent, e.v);

        // If including this edge doesn't form a cycle
        if (setU != setV) 
        {
            mst.push_back(e);
            totalCost += e.weight;
            unionSet(parent, setU, setV);
            cout << "Added edge: " << e.u << "-" << e.v << " with weight " << e.weight << endl;
        } else 
        {
            cout << "Skipped edge: " << e.u << "-" << e.v << " (forms cycle)" << endl;
        }

        // Stop if MST is complete
        if (mst.size() == V - 1) break;
    }

    // Final Output
    cout << endl;
    cout << "Minimum Spanning Tree (MST):" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "| Starting Vertex | Ending Vertex | Weight |" << endl;
    cout << "--------------------------------------------" << endl;
    for (auto& e : mst) {
        cout << "| " << setw(8) << e.u << setw(10)
             << " | " << setw(8) << e.v << setw(8)
             << " | " << setw(3) << e.weight << setw(5) << " |" << endl;
    }
    cout << "--------------------------------------------" << endl;
    cout << "Total cost of MST: " << totalCost << endl;
}

int main()
{
    cout << "\t\t=====================" << endl;
    cout << "\t\t  Kruskal Algorithm  " << endl;
    cout << "\t\t=====================" << endl;

    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<Edge> edges(E);
    cout << "Enter edges (Starting Vertex, Ending Vertex, Weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    cout << endl;

    // Perform Kruskal's Algorithm
    kruskal(V, edges);

    cout << "\nCompiled by : Subodh Ghimire " << endl;
    return 0;
}

    