#include <iostream>
using namespace std;

int main() {
    char names[4] = {'A', 'B', 'C', 'D'};
    int graph[4][4] = {0};

    graph[0][1] = 3;   // A -> B, weight 3
    graph[0][2] = 2;   // A -> C, weight 2
    graph[2][1] = 1;   // C -> B, weight 1
    graph[3][0] = 4;   // D -> A, weight 4

    cout << "Adjacency Matrix:" << endl;
    cout << "   A  B  C  D" << endl;
    for (int i = 0; i < 4; i++) {
        cout << names[i] << "  ";
        for (int j = 0; j < 4; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}