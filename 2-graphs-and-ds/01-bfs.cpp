#include <iostream>
#include <vector>
#include <queue>

using std::cerr;
using std::cout;
using std::vector;
using std::queue;

class Graph {
    vector<vector<int>> adjList;
    int V;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void joinVertex(int p, int q) {
        if (p >= V || q >= V) {
            cerr << "Out of Bounds\n";
            return;
        }

        adjList[p].push_back(q);
        adjList[q].push_back(p);
    }

    void printGraph() {
        for(int i = 0; i < adjList.size(); i++) {
            cout << i << ": ";
            for(int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    vector<int> BFS(int startV) {
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> nodes;

        q.push(startV);
        visited[startV] = true;

        while (!q.empty()) {
            int curV = q.front();
            q.pop();
            nodes.push_back(curV);

            for(int neighbour : adjList[curV]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return nodes;
    }
};

int main() {
    
}