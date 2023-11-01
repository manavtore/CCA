
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    void kruskalMST() {
        vector<Edge> resultMST;
        sort(edges.begin(), edges.end(), compareEdges);
        vector<int> parent(V, -1);

        for (const Edge& edge : edges) {
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);

            if (srcParent != destParent) {
                resultMST.push_back(edge);
                parent[srcParent] = destParent;
            }
        }

        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (const Edge& edge : resultMST) {
            cout << edge.src << " - " << edge.dest << " (" << edge.weight << ")\n";
        }
    }

private:
    int findParent(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return findParent(parent, parent[vertex]);
    }
};

int main() {
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.kruskalMST();

    return 0;
}
