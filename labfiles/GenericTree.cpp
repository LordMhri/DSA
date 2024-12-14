#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    vector<Node *> children;

    Node(int data) : data(data) {};
};

class GenericTree
{
private:
    Node *head;

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        for (Node *child : node->children)
        {
            deleteTree(child);
        }
        delete node;
    }

    void preOrderTraversal(Node *node){
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        for (Node *child : node->children)
        {
            preOrderTraversal(child);
        }
        }
    
    void postOrderTraversal(Node *node){
        if (node == nullptr)
        {
            return;
        }
        for (Node *child : node->children)
        {
            postOrderTraversal(child);
        }

        cout << node->data << " ";
    }

    Node *search(Node *node, int data)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data == data)
            return node;
        for (Node *child : node->children)
        {
            Node *result = search(child, data);
            if (result != nullptr)
                return result;
        }
        return nullptr;
    }

    void display(Node *node, int depth = 0){
        if (node == nullptr)
            return;
        for (int i = 0; i < depth; ++i)
            cout << "--";
        cout << node->data << endl;
        for (Node *child : node->children)
        {
            display(child, depth + 1);
        }
    }

public:
    GenericTree() : head(nullptr) {};

    ~GenericTree() {
        deleteTree(head);
    }

    void setHead(int data)
    {
        if (head != nullptr)
            deleteTree(head);
        head = new Node(data);
    }

    void preOrderTraversal() {
        preOrderTraversal(head);
    };

    void postOrderTraversal(){
        postOrderTraversal(head);
    }

    Node *search(int data){
        return search(head, data);
    }

    void addChildren(Node *parent, int data){
        Node *newNode = new Node(data);
        parent->children.push_back(newNode);
    }


    void display(){
        display(head);
    }
};

int main()
{
    GenericTree tree;
    tree.setHead(1);
    Node *root = tree.search(1);
    tree.addChildren(root, 2);
    tree.addChildren(root, 3);
    Node *node2 = tree.search(2);
    tree.addChildren(node2, 4);
    tree.addChildren(node2, 5);
    Node *node3 = tree.search(3);
    tree.addChildren(node3, 6);
    tree.addChildren(node3, 7);

    cout << "Pre-order Traversal: ";
    tree.preOrderTraversal();

    cout << "Post-order Traversal: ";
    tree.postOrderTraversal();

    cout << "Tree Structure:" << endl;
    tree.display();

    return 0;
}