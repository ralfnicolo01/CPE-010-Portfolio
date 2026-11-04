#include <iostream>

const int MAX = 20;

// A.1 Create a Graph: add a vertex, add an edge, display the graph vertices
class Graph {
    char vertices[MAX];
    char edgeFrom[MAX * MAX];
    char edgeTo[MAX * MAX];
    int vCount;
    int eCount;

    bool exists(char v) {
        for (int i = 0; i < vCount; i++)
            if (vertices[i] == v) return true;
        return false;
    }
public:
    Graph() {
        vCount = 0;
        eCount = 0;
    }

    // Add a vertex: adds vertex to the graph
    void addVertex(char v) {
        if (exists(v)) {
            std::cout << "Vertex " << v << " already exists" << std::endl;
            return;
        }
        if (vCount == MAX) {
            std::cout << "Graph is full" << std::endl;
            return;
        }
        vertices[vCount] = v;
        vCount++;
    }

    // Add an edge: adds an edge between the two vertices of a graph
    void addEdge(char a, char b) {
        if (!exists(a) || !exists(b)) {
            std::cout << "Vertex not found" << std::endl;
            return;
        }
        edgeFrom[eCount] = a;
        edgeTo[eCount] = b;
        eCount++;
    }

    // Display the graph vertices: displays the vertices of a graph
    void displayVertices() {
        std::cout << "Vertices: ";
        for (int i = 0; i < vCount; i++)
            std::cout << vertices[i] << " ";
        std::cout << std::endl;
    }

    // Display the edges that were added
    void displayEdges() {
        std::cout << "Edges: ";
        for (int i = 0; i < eCount; i++)
            std::cout << "(" << edgeFrom[i] << "," << edgeTo[i] << ") ";
        std::cout << std::endl;
    }
};

int main() {
    Graph g;
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('D', 'E');
    g.displayVertices();
    g.displayEdges();
    return 0;
}