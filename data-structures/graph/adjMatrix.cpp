#include <vector>
using std::vector;

class GraphAdjMatrix {
    vector<vector<int>> matrix;
    int V;
public:
    GraphAdjMatrix(int noOfVertices) {
        V = noOfVertices;
        matrix.resize(V);
    }
};