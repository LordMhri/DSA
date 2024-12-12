#include <iostream>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int data;

    Node(int data) : left(nullptr), right(nullptr), data(data) {};
};

class BinarySearchTree
{
private:
    Node *root;
public:
    BinarySearchTree() : root(nullptr) {};
    
    //deletion by copying 
    //deletion by merging

    Node* deleteNode(Node *root,int value){
        if (root == nullptr)
        {
            return root;
        }   
        if (root->data < value)
        {
            root->right = deleteNode(root, value);
        } else if (root->data > value){
            root->left = deleteNode(root, value);
        } else {
            //this means we've identifed the node to be removed
            //if node has only one child
            //left or right is nullptr
            if (root->left == nullptr)
            {
                //right child exists so
                //make right child the deleted node?
                Node *temp = root->right;
                delete root;
                return temp;
            } else if(root->right == nullptr){
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data);
        }
        return root;
    }

    Node *maxValueNode(Node* root){
        Node *current = root;
        while (current && current->right != nullptr){
            current = current->right;
        }

        return current;
    }

    Node *minValueNode(Node *root){
        Node *current = root;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void insert(int data) {
        if (!root)
        {
            root = new Node(data);
            return;
        }

        Node *current = root;

        while (true)
        {
            if (data < current->data) { // if the current data is less than the root data
                if (current->left == nullptr) //if left node doesn't exist
                {
                    current->left = new Node(data);
                    break;
                }
                current = current->left; 
                // continue as long as we dont find an appropriate place
                // to put the new node in

            } else {
                if (current->right == nullptr)
                {
                    current->right = new Node(data);
                    break;
                }
                current = current->right;
            }
        }
    }

        void printInorderTraversal() {
            printINT(root);
        }

        void printPostOrderTraversal(){
            printPST(root);
        }

        void printPreOrderTraversal(){
            printPRE(root);
        }

        

    private:
    //in order traversal left -> parent -> right
        void inorderTraversal(Node *root) {
            if (root == nullptr) {
                return;
            }
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }

        void postOrderTraversal(Node *node){
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
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            
        }

        void printPST(Node *root){
            postOrderTraversal(root);
            cout << endl;
        }

        void printINT(Node *root) {
            inorderTraversal(root);
            cout << endl;
        }

        void printPRE(Node *root){
            preOrderTraversal(root);
            cout << endl;
        }
};

int main(int argc, char const *argv[])
{
    BinarySearchTree Btree;
    int num = 4096;

    for (int i = 0; i < 10; i++)
    {
        Btree.insert(i+1);
    }

    for (int i = 0; i < 10; i++)
    {
        num = num / 16;
        Btree.insert(num);
    }

    Btree.printInorderTraversal();

    cout << "Now post order\n";
    Btree.printPostOrderTraversal();

    cout << "Now pre order\n";
    Btree.printPreOrderTraversal();

    return 0;
}



/*
                        9

                    8       12
                        11



*/