#include <bits/stdc++.h>
using namespace std;

struct Graph {
    vector<vector<int>> adj_list;
    int v;

    Graph(int count) {
        v = count;
        adj_list.resize(v);
    }

    void join(int a, int b) {
        if (a >= v || b >= v) {
            cout << "out of bounds\n";
            return;
        }
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
};

void bfs(Graph& graph, int startVertex, vector<bool>& visitedList) {
    queue<int> q;

    q.push(startVertex);
    visitedList[startVertex] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int connectedVertex : graph.adj_list[v]) {
            if (!visitedList[connectedVertex]) {
                q.push(connectedVertex);
                visitedList[connectedVertex] = true;
            }
        }
    }
}

int clusters(Graph& graph) {
    int count = 0;
    vector<bool> visited(graph.v, false);
    for (int i = 0; i < graph.v; i++) {
        if (!visited[i]) {
            bfs(graph, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    Graph g(10);

    g.join(0, 2);
    g.join(0, 4);
    g.join(2, 4);
    g.join(4, 6);
    g.join(4, 8);
    g.join(1, 3);
    g.join(5, 7);
    g.join(5, 9);

    int cluster_count = clusters(g);
    cout << cluster_count << '\n';
}