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

vector<int> shortest_path(Graph& g, int source) {
    vector<int> dist(g.v, INT_MAX);
    vector<bool> visited(g.v, false);
    queue<int> q;

    visited[source] = true;
    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int vertex : g.adj_list[v]) {
            if (!visited[vertex]) {
                dist[vertex] = min(dist[vertex], dist[v] + 1);
                visited[vertex] = true;
                q.push(vertex);
            }
        }
    }
    return dist;
}

int main() {
    Graph g(6, false);

    g.join(0, 1);
    g.join(0, 3);
    g.join(1, 2);
    g.join(3, 4);
    g.join(2, 5);
    g.join(4, 5);
    
    vector<int> res = shortest_path(g, 1);
    for (int x : res) {
        cout << x << ' ';
    } cout << endl;
}