#include <iostream>

const int MAX = 20;

// A.2 Adjacency Matrix
class GraphMatrix {
    char vertices[MAX];
    int matrix[MAX][MAX];
    int vCount;
    bool directed;

    int indexOf(char v) {
        for (int i = 0; i < vCount; i++)
            if (vertices[i] == v) return i;
        return -1;
    }
public:
    GraphMatrix(bool isDirected) {
        vCount = 0;
        directed = isDirected;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                matrix[i][j] = 0;
    }

    void addVertex(char v) {
        if (indexOf(v) != -1 || vCount == MAX) return;
        vertices[vCount] = v;
        vCount++;
    }

    // weight is 1 for an unweighted graph
    void addEdge(char from, char to, int weight = 1) {
        int i = indexOf(from);
        int j = indexOf(to);
        if (i == -1 || j == -1) {
            std::cout << "Vertex not found" << std::endl;
            return;
        }
        matrix[i][j] = weight;
        if (!directed) matrix[j][i] = weight;
    }

    void displayVertices() {
        std::cout << "Vertices: ";
        for (int i = 0; i < vCount; i++)
            std::cout << vertices[i] << " ";
        std::cout << std::endl;
    }

    void displayMatrix() {
        std::cout << "  ";
        for (int i = 0; i < vCount; i++)
            std::cout << vertices[i] << " ";
        std::cout << std::endl;
        for (int i = 0; i < vCount; i++) {
            std::cout << vertices[i] << " ";
            for (int j = 0; j < vCount; j++)
                std::cout << matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }
};

int main() {
    // Undirected graph
    std::cout << "UNDIRECTED GRAPH" << std::endl;
    GraphMatrix g1(false);
    g1.addVertex('A');
    g1.addVertex('B');
    g1.addVertex('C');
    g1.addVertex('D');
    g1.addVertex('E');
    g1.addEdge('A', 'B');
    g1.addEdge('A', 'C');
    g1.addEdge('A', 'D');
    g1.addEdge('B', 'E');
    g1.addEdge('C', 'D');
    g1.addEdge('D', 'E');
    g1.displayVertices();
    g1.displayMatrix();

    // Weighted graph
    std::cout << std::endl << "WEIGHTED GRAPH" << std::endl;
    GraphMatrix g2(true);
    g2.addVertex('A');
    g2.addVertex('B');
    g2.addVertex('C');
    g2.addVertex('D');
    g2.addVertex('E');
    g2.addEdge('A', 'B', 4);
    g2.addEdge('A', 'C', 3);
    g2.addEdge('C', 'D', 2);
    g2.addEdge('D', 'B', 1);
    g2.addEdge('D', 'E', 1);
    g2.addEdge('E', 'A', 1);
    g2.displayVertices();
    g2.displayMatrix();
    return 0;
}