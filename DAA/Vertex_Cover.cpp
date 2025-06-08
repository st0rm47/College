#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int solutionCount = 0;

// Function to check if a given set of vertices is a vertex cover
bool isVertexCover(const vector<pair<int, int>> &edges, const set<int> &cover) {
    for (auto &edge : edges) {
        if (cover.find(edge.first) == cover.end() && cover.find(edge.second) == cover.end())
            return false; // Edge not covered
    }
    return true;
}

// Function to print a vertex cover solution
void printCover(const set<int> &cover) {
    solutionCount++;
    cout << "\nSolution #" << solutionCount << " (Vertex Cover): { ";
    for (int v : cover) {
        cout << v << " ";
    }
    cout << "}\n";
}

// Function to solve the vertex cover problem (brute-force)
void vertexCoverBruteForce(int V, const vector<pair<int, int>> &edges) {
    int totalSubsets = 1 << V; // 2^V subsets

    for (int mask = 0; mask < totalSubsets; ++mask) {
        set<int> cover;
        for (int i = 0; i < V; ++i) {
            if (mask & (1 << i))
                cover.insert(i);
        }
        if (isVertexCover(edges, cover)) {
            printCover(cover);
        }
    }
    if (solutionCount == 0)
        cout << "\nNo vertex cover found.\n";
}

int main() {
    cout << "\t\t========================" << endl;
    cout << "\t\t  Vertex Cover Problem  " << endl;
    cout << "\t\t========================" << endl;

    int V, E;
    cout << "\nEnter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, int>> edges;
    cout << "\nEnter the edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vertexCoverBruteForce(V, edges);

    cout << "\nTotal solutions found: " << solutionCount << endl;
    cout << "\nCompiled by : Subodh Ghimire" << endl;
    return 0;
}
