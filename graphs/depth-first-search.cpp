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

void dfs_recursive_helper (Graph& g, int startVertex, vector<bool>& visited, vector<int>& result) {
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

vector<int> dfs_iterative(Graph& g, int startVertex) {
    vector<int> result;
    vector<bool> visited(g.v, false);
    stack<int> stk;

    stk.push(startVertex);

    while (!stk.empty()) {
        int vertex = stk.top();
        stk.pop();
        if (!visited[vertex]) {
            visited[vertex] = true;
            result.push_back(vertex);
            int size = g.adj_list[vertex].size();
            for (int i = size - 1; i >= 0; i--) {
                int node = g.adj_list[vertex][i];
                if (!visited[node]) stk.push(node);
            }
        }
    }
    return result;
}

int main() {
    Graph g(6, false);

    g.join(0, 1);
    g.join(0, 3);
    g.join(1, 2);
    g.join(3, 4);
    g.join(2, 5);
    g.join(4, 5);

    
    vector<int> result = dfs_iterative(g, 0);
    for (int v : result) {
        cout << v << ' ';
    }
    cout << endl;
}