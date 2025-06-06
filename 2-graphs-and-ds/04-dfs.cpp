#include <bits/stdc++.h>
using namespace std;

struct Graph {
    vector<vector<int>> adj_list;
    int v;
    bool directed;

    Graph(int count, bool dir) {
        directed = dir;
        v = count;
        adj_list.resize(v);
    }

    void join(int a, int b) {
        if (a >= v || b >= v) {
            cout << "out of bounds\n";
            return;
        }
        adj_list[a].push_back(b);
        if (!directed) adj_list[b].push_back(a);
    }
};

void dfs_recursive_helper (Graph& g,
                           int startVertex,
                           vector<bool>& visited,
                           vector<int>& result) {
    visited[startVertex] = true;
    result.push_back(startVertex);
    for (int connectedVertices : g.adj_list[startVertex]) {
        if (!visited[connectedVertices]) {
            dfs_recursive_helper(g, connectedVertices, visited, result);
        }
    }
}

vector<int> dfs_recursive(Graph& g, int startVertex) {
    vector<bool> visited(g.v, false);
    vector<int> result;
    dfs_recursive_helper(g, startVertex, visited, result);
    return result;
}

int main() {

}