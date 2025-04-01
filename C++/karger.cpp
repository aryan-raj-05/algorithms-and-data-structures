/*
    Karger's Algorithms: to find the minimum cut of a graph.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::pair;
using std::vector;

struct Graph {
    int V, E;
    vector<pair<int, int>> edges;

    Graph(int vertices, int edges) : V(vertices), E(edges) {}

    void addEdge(int src, int dest) {
        edges.emplace_back(src, dest);
    }
};

struct UnionFind {
    vector<int> id;
    vector<int> sz;

    UnionFind(int n) : id(n), sz(n, 1) {
        for(int i = 0; i < n; i++) {
            id[i] = i;
        }
    }

    int find(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
    void unionBySize(int p, int q) {
        int i = find(p);
        int j = find(q);

        if (i == j) return;
        if (sz[i] < sz[j]) {  id[i] = j; sz[j] += sz[i];  }
        else               {  id[j] = i; sz[i] += sz[j];  }
    }
};

int kargerMinCut(int V, const vector<pair<int, int>>& edges) {
    auto edgeList = edges;

    UnionFind uf(V);

    int vertices = V;

    while (vertices > 2) {
        int i = rand() % edgeList.size();
        int vertex1 = uf.find(edgeList[i].first);
        int vertex2 = uf.find(edgeList[i].second);

        if (vertex1 == vertex2) continue;
        else {
            vertices--;
            uf.unionBySize(vertex1, vertex2);
        }
    }

    int cutEdges = 0;
    for(int i = 0; i < edgeList.size(); i++) {
        int v1 = uf.find(edgeList[i].first);
        int v2 = uf.find(edgeList[i].second);
        if (v1 != v2) cutEdges++;
    }

    return cutEdges;
}

int main() {
    int V = 4, E = 5;
    Graph graph(V, E);
    
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    int minCut = kargerMinCut(graph.V, graph.edges);
    cout << "Minimum cut: " << minCut << "\n";
    return 0;
}