#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int v;
    bool directed;

    Graph(int vertices, bool isDirected) {
        v = vertices;
        directed = isDirected;
        adjList.resize(v);
    }

    void joinVertex(int v1, int v2) {
        if (v1 >= v || v2 >= v) {
            cerr << "Invalid Operation\n";
            return;
        }
        adjList[v1].push_back(v2);
        if (!directed) adjList[v2].push_back(v1);
    }

    void printGraph() {
        int counter = 0;
        while (counter < v) {
            cout << counter << ": ";
            for (int x : adjList[counter]) 
                cout << x << " ";
            cout << '\n';
            counter++;
        }
    }

    vector<int> bfs(int startVertex) {
        vector<int> result;
        vector<bool> isVisited(v, false);
        queue<int> q;
    
        q.push(startVertex);
        isVisited[startVertex] = true;
    
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            result.push_back(v);
            for (int neighbor : adjList[v]) {
                if (!isVisited[neighbor]) {
                    q.push(neighbor);
                    isVisited[neighbor] = true;
                }
            }
        }

        return result;
    }
};


int main() {
    Graph g(6, false);

    g.joinVertex(0, 1);
    g.joinVertex(0, 3);
    g.joinVertex(1, 2);
    g.joinVertex(3, 4);
    g.joinVertex(2, 5);
    g.joinVertex(4, 5);

    
    vector<int> result = g.bfs(0);
    for (int v : result) {
        cout << v << ' ';
    }
    cout << endl;
}