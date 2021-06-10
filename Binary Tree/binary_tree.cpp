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

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void printPre(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

void printIn(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printIn(root->left);
    cout << root->data << " ";
    printIn(root->right);
}

void printPost(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout << root->data << " ";
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printkthLevel(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printkthLevel(root->left, k - 1);
    printkthLevel(root->right, k - 1);
    return;
}

void printAllLevel(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printkthLevel(root, i);
        cout << endl;
    }
    return;
}

istream &operator>>(istream &is, node *&root)
{
    root = buildTree();
    return is;
}

ostream &operator<<(ostream &os, node *root)
{
    printAllLevel(root);
    return os;
}

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
        else{

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
}

int count(node*root){
    if(root == NULL){
        return 0;
    }

    return 1 + count(root->left) + count(root->right);
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);

    return (max(op1, max(op2, op3)));
}

class Pair
{
public:
    int height;
    int diameter;
};

Pair fastDiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }
    //Otherwise
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int replaceSum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    //Recursive Part
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;
    return temp + root->data;
}

class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHeightBalance(node *root)
{
    HBPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }
    //Recurisve Case
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 && left.balance && right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }
    return p;
}

node *buildTreeFromArray(int *arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildTreeFromArray(arr, s, mid - 1);
    root->right = buildTreeFromArray(arr, mid + 1, e);

    return root;
}

node *createTreeFromTrav(int *in, int *pre, int s, int e)
{
    static int i = 0;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    node *root = new node(pre[i]);

    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}

void printRightView(node *root, int level, int &maxLevel)
{
    if (root == NULL)
    {
        return;
    }
    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }

    printRightView(root->right, level + 1, maxLevel);
    printRightView(root->left, level + 1, maxLevel);
    return;
}

int main()
{
    // node *root = buildTree();
    // bfs(root);
    // // Preorder
    // printPre(root);
    // cout << endl;
    // // Inorder
    // printPre(root);
    // cout << endl;
    // // Postorder
    // printPre(root);
    // cout << endl;
    // // height
    // cout << height(root) << endl;
    // // cout<<height(root)<<endl;
    // // printkthLevel(root,3);
    // printAllLevel(root);
    // cout<<count(root)<<endl;
    // cout << diameter(root) << endl;
    // Pair p = fastDiameter(root);
    // cout << p.height << endl;
    // cout << p.diameter << endl;
    // bfs(root);
    // cout << endl;
    // replaceSum(root);
    // bfs(root);
    // if (isHeightBalance(root).balance)
    // {
    //     cout << "Balanced";
    // }
    // else
    // {
    //     cout << "Not a Balanced Tree" << endl;
    // }
    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = 7;

    // node *root = buildTreeFromArray(a, 0, n - 1);
    // bfs(root);
    // int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    // int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    // int n = sizeof(in) / sizeof(int);

    // node *root = createTreeFromTrav(in, pre, 0, n - 1);
    // bfs(root);
    node *root = NULL;
    cin >> root;
    cout << root << endl;
    int maxLevel = -1;
    printRightView(root, 0, maxLevel);
    return 0;
}
