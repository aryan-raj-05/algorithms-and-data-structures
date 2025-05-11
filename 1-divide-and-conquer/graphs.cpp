#include <iostream>
#include <unordered_map>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

// Adjancency Matrix implementation of Graphs
template <typename T>
class graphAM {
    vector<vector<int>> matrix;
    unordered_map<T, int> table;
    int cur = 0;
    bool directed;

public:
    graphAM(int V, bool ordered = false) {
        directed = ordered;
        matrix.resize(V, vector<int>(V, 0));
    }

    void addVertex(T name) {
        if (cur >= matrix.size()) {
            cerr << "Not enough space\n";
            return;
        }
        table.insert({name, cur++});
    }

    void joinV(T v1, T v2) {
        if (table.find(v1) == table.end() || table.find(v2) == table.end()) {
            cerr << "One or both vertex have not been added.\n";
            return;
        }

        int idxv1 = table.at(v1);
        int idxv2 = table.at(v2);
        matrix[idxv1][idxv2] = 1;
        if (!directed) {  matrix[idxv2][idxv1] = 1;  }
    }

    void printGraph() {
        for(int i = 0; i < cur; i++) {
            for(int j = 0; j < cur; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << '\n';
        }
    }
};

// Adjacency List implementation of Graphs
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