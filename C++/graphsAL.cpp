#include <iostream>
#include <unordered_map>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

template <typename T>
class graphAL {
    vector<vector<int>> adjList;
    unordered_map<T, int> umap;
    int curVIDToAssign = 0;
    bool directed;

public:
    graphAL(bool isDirected = false) { // input being number of vertices
        directed = isDirected;
    }

    void addVertex(T name) {
        if (umap.find(name) != umap.end()) {
            cerr << "Vertex already exist\n";
            return;
        }
        umap[name] = curVIDToAssign++;
        adjList.push_back({});
    }

    void addVertex(const vector<T>& list) {
        for (const T& entry : list) {
            if (umap.find(entry) == umap.end()) {
                umap[entry] = curVIDToAssign++;
                adjList.push_back({});
            }
        }
    }

    void joinV(T v1, T v2) {
        if (umap.find(v1) == umap.end() || umap.find(v2) == umap.end()) {
            cerr << "One or Both vertex don't exist\n";
            return;
        }

        int idxv1 = umap[v1];
        int idxv2 = umap[v2];

        adjList[idxv1].push_back(idxv2);
        if(!directed) {
            adjList[idxv2].push_back(idxv1);
        }
    }

    void printGraph() {
        for(int i = 0; i < adjList.size(); i++) {
            cout << i << " : ";
            for(int n : adjList[i]) {
                cout << n << " ";
            }
            cout << '\n';
        }

        cout << "The mapping of digits to Vertex is:\n";
        for(auto&[key, value] : umap) {
            cout << '(' << key << ", " << value << ") ";
        }
        cout << '\n';
    }
};

int main() {
    graphAL<char> G;

    vector<char> vertices = {'A', 'B', 'C', 'D'};
    G.addVertex(vertices);

    G.joinV('A', 'C');
    G.joinV('A', 'D');
    G.joinV('A', 'B');
    G.joinV('C', 'B');

    G.printGraph();
}