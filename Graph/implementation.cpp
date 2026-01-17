#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Adjacency list
    unordered_map<int, vector<int>> adj;

    // Function to add an edge
    void addEdge(int u, int v, bool directed) {
        adj[u].push_back(v);

        // If graph is undirected, add reverse edge
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // Function to print the graph
    void printGraph() {
        for (auto node : adj) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cout << "Enter the Number of Nodes: " << endl;
    cin >> n;

    cout << "Enter the Number of Edges: " << endl;
    cin >> m;

    Graph g;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // false → undirected graph
        g.addEdge(u, v, false);
    }

    cout << "\nAdjacency List Representation:\n";
    g.printGraph();

    return 0;
}
