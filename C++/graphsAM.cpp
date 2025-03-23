#include <iostream>
#include <unordered_map>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::unordered_map;
using std::vector;

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
