#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }

    Node *n = new Node(d);
    n->next = head;
    head = n;
}

int length(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtTail(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *n = new Node(d);
        return;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new Node(d);
    return;
}

void insertAtMiddle(Node *&head, int d, int p)
{
    // corner case
    if (head == NULL or p == 0)
    {
        insertAtHead(head, d);
        return;
    }
    else if (p > length(head))
    {
        insertAtTail(head, d);
    }

    else
    {
        // take p-1 jumps
        int jump = 1;
        Node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        // create new node
        Node *n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ->"
             << " ";
        head = head->next;
    }
}

void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head->next;
    delete head;
    head = temp;
}

// Linear Search
bool linear_search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
            temp = temp->next;
        }
    }
    return false;
}

// Recursive linear Search
bool recursiveSearch(Node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }

    if (head->data == key)
    {
        return true;
    }
    else
    {
        recursiveSearch(head->next, key);
    }
}

Node *take_input()
{
    int d;
    cin >> d;
    Node *head = NULL;
    while (d != -1)
    {
        insertAtHead(head, d);
        cin >> d;
    }
    return head;
}

ostream& operator<<(ostream &os, Node *head)
{
    display(head);
    return os;
}

istream &operator>>(istream &is, Node *&head)
{
    head = take_input();
    return is;
}

void reverse(Node*&head){
    Node*C = head;
    Node*P = NULL;
    Node*N;
    while(C!=NULL){
        // save next node
        N = C->next;
        // update current node to previous node
        C->next = P;
        // update prev and next node
        P = C;
        C = N;
    }
    head = P;
}

Node *midPoint(Node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
// merge 2 sorted linked list
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    Node *c;

    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(b->next, a);
    }
    return c;
}

int main()
{
    Node* head;
    Node* head1;
    cin>>head>>head1;
    cout << head << endl << head1<<endl;
    Node *sort_list = merge(head, head1);
    cout << sort_list;
    // Node *mid = midPoint(head);
    // cout << mid->data;
    // reverse(head);
    // cout << head;
    // Node *head = take_input();
    // Node *head1 = take_input();
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);
    // insertAtHead(head, 0);
    // display(head);
    // cout << endl;
    // insertAtMiddle(head, 3, 3);
    // insertAtTail(head, 5);
    // display(head);
    // cout << endl;

    return 0;
}
