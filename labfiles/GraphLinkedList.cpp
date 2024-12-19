#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {};
};

class GraphLinkedList
{
public:
    Node** lists;
    int vertices;
    GraphLinkedList(int vertices)
    {
        this->vertices = vertices;
        lists = new Node *[vertices];
    }


    void addEdge(int u,int v){
        Node *newNode = new Node(v);
        newNode->next = lists[u];
        lists[u] = newNode;

        newNode = new Node(u);
        newNode->next = lists[v];
        lists[v] = newNode;
    }

void printGraph() {
    for (int i = 0; i < vertices; ++i) {
        Node* temp = lists[i];
        cout << "list of vertex for " << i << "\nhead ";
        while (temp) {
            cout << "-> " << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
}
};

int main(int argc, char const *argv[])
{
    GraphLinkedList g(5);
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(3, 1);
    g.addEdge(3, 1);
    g.addEdge(3, 2);

    g.printGraph();
    return 0;
}




