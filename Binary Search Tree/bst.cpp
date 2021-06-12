#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Accepts the old root node & data and returns the new root node
node *insertInBST(node *root, int data)
{
    //Base Case
    if (root == NULL)
    {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}

node *build()
{
    //Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin >> d;

    node *root = NULL;

    while (d != -1)
    {
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}
//Print the BST Level By Level
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << ",";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}
//Inorder Print
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

bool search(Node *root, int key)
{
    //base case
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

Node *removeNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        //This is the node to be deleted
        //3 cases - 0 , 1, 2 children
        //1. leaf node
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL and root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            //find inorder successor
            Node *temp = root->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            //copy the temp data to root
            root->data = temp->data;
            //rec delete the temp->data from right subtree
            root->right = removeNode(root->right, temp->data);
            return root;
        }
    }
    else if (key < root->data)
    {
        root->left = removeNode(root->left, key);
    }
    else
    {
        root->right = removeNode(root->right, key);
    }
    return root;
}

bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}

int main()
{
    node *root = build();
    inorder(root);
    cout << endl;
    bfs(root);

    return 0;
}
