#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {};
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree() : root(nullptr) {};

    void insert(int data)
    {
        root = insertRec(root, data);
    }

    void deleteNode(int value)
    {
        root = deleteRec(root, value);
    }

    void printInorderTraversal()
    {
        inorderTraversal(root);
        cout << endl;
    }

    void printPostOrderTraversal()
    {
        postOrderTraversal(root);
        cout << endl;
    }

    int height(){
        return heightOfTree(root);
    }

    
    
    int depthOfANode(Node* node, int data, int depth = 0) {
        if (node == nullptr) {
            return -1; // Node not found
        }
        if (node->data == data) {
            return depth;
        }
        int leftDepth = depthOfANode(node->left, data, depth + 1);
        if (leftDepth != -1) {
            return leftDepth;
        }
        return depthOfANode(node->right, data, depth + 1);
    }

    void depthOfANode(int data){
        int depth = depthOfANode(root, data);
        if (depth != -1) {
            cout << "Depth of node with data " << data << " is: " << depth << endl;
        } else {
            cout << "Node with data " << data << " not found in the tree." << endl;
        }
    }

    void printPreOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
    }

private:
    int heightOfTree(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int left_height = heightOfTree(root->left);
        int right_height = heightOfTree(root->right);
        if (left_height >= right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }

    Node *insertRec(Node *node, int data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->data)
        {
            node->left = insertRec(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertRec(node->right, data);
        }
        return node;
    }

    Node *deleteRec(Node *root, int value)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (root->data < value)
        {
            root->right = deleteRec(root->right, value);
        }
        else if (root->data > value)
        {
            root->left = deleteRec(root->left, value);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    Node *deleteMerge(Node*root,int value){
        if (root == nullptr)
        {
            return root;
        } else if(root->left == nullptr){
            root->right = deleteMerge(root->right,value);
        } else if(root->right == nullptr){
            root->left = deleteMerge(root->left,value);
        } else {
            if (root->left ==nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp; 
            } else if (root->right == nullptr){
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minValueNode(root->right);
            temp->right = root->right;
            return root->left;
        }
        return root;
    }

    Node *minValueNode(Node *root)
    {
        Node *current = root;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *maxValueNode(Node *root)
    {
        Node *current = root;
        while (current && current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void postOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    void preOrderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
};

int main()
{
    BinarySearchTree Btree;
    int num = 4096;

    for (int i = 1; i < 10; i++)
    {
        Btree.insert(i + 1);
    }

    for (int i = 0; i < 10; i++)
    {
        num = num / 16;
        Btree.insert(num);
    }

    Btree.printInorderTraversal();

    cout << "Now post order\n";
    Btree.printPostOrderTraversal();

    Btree.deleteNode(121312);

    cout << "Now pre order\n";
    Btree.printPreOrderTraversal();

    Btree.depthOfANode(16);

    cout << "Height of tree is " << Btree.height() << "\n";

    return 0;
}

/*
                        9

                    8       12
                        11



*/