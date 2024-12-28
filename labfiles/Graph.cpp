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

    void DFS(int startVertex){
        vector<bool> visited (V,false);
        DFS(visited,startVertex);

    }

private:
    int V;
    vector<vector<int>> adj;

    void DFS(vector<bool>&visited,int startVertex){
        visited[startVertex] = true;

        cout << "Just visited " << startVertex << endl;

        for (int &i: adj[startVertex])
        {
            if (!visited[i])
            {
                DFS(visited,i);
            }
            

        }
        
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 4);
    g.addEdge(0, 1); 
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.BFS(0);
    g.printGraph();

    g.DFS(0);
    /*
        for the DFS call

        first we process 0 so print "visited 0"
        then we process the first neighbor of 0 , in the order they were added  so 0 : 4,1
        so we process 4 first so print "visited 4"
        now for 4 when we connected 0 and 4 we added 0 as a neighbor to 4
        so 4 : 0 then we added 4 as a neighbor to 3 which means 3 is a neighbor to 4
        so 4: 0,3 then we added 5 so 4 looks like 4:0,3,5
        now the recursive call calls 0 but we've already seen it so we pass it and then call
        the next neighbor which is 3 so print "visited 3"
        then go to the neighbors of 3 which are 2 and 4
        so we process 2 so "visited 2"
        and we go to the neighbors of 2 which are 1 and 2
        so we process 1 so print "visited 1"
        and we go to the neighbors of 1 which are 0,5,2
        we've seen 0 before so pass it we go to 5
        so we process 5 so "visited 5" and we've seen 2 before so the call stack pops DFS(1) from the call stack
        when DFS(5) finishes, the program returns to DFS(1), which continues with the next neighbor.
        Since no more unvisited neighbors are found, we then return to DFS(2).
        The calls stack continues to unwind to DFS(3), DFS(4) then DFS(0).
    

        we're left with visited 0,visited 4,visited 3,visited 2,visited 1 and visited 5
    */

    return 0;
}