#include <iostream>
#include <vector>


using namespace std;

class Graph {
public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << v << ": ";
            for (int w : adj[v]) {
                cout << w << " ";
            }
            cout << endl;
        }
    }

private:
    int V;
    vector<vector<int>> adj;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.printGraph();

    return 0;
}