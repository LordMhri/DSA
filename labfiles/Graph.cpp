#include <iostream>
#include <vector>
#include <deque>


using namespace std;

class Graph {
public:
    Graph(int V) : V(V), adj(V) {};

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
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

    void BFS(int startVertex){
        vector<bool> visited(V,false); //a vector of boolean values to check if we've seen that node before
        
        
        deque<int> queue;

        visited[startVertex] = true; //mark our starting index as true because we start there
        queue.push_back(startVertex);

        while (!queue.empty())
        {
            int currVertex = queue.front();
            cout << "Visited " <<  currVertex <<"\n";
            queue.pop_front();
            /*in the for loop
            i is an iterator,
            adj[currVertex] holds the neighbors of the currentVertex
            meaning each value in the adj[currVertex] is connected to the currentVertex vertex
            so we iterate starting from the first element in the adjaceny list of currVertex adj[currVert].begin()
            until the end adj[currVert].end()
            */
            for (auto i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i)
            {
                //before dereferencing i points to the memory location of the current element
                //we dereference i to get the actual value and assign it to adjVertex
                int adjVertex = *i;
                // if we've seen adjVertex before then that means it has either been processed before
                // or pushed to the queue for processing
                // so no need to process it again
                // if we've never seen it then that means we should process it
                // so we  mark it as seen
                // and add it to the queue to be processed
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
            
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
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    g.BFS(0);
    g.printGraph();

    return 0;
}