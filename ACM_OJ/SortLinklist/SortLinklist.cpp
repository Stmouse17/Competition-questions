#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node (int x)
    {
        data = x;
        next = nullptr;
    }
};

void PrintList(Node* head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

Node* CreateList (int n)    //tailinsert
{
    Node* head = nullptr;
    Node* tail = head;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Node* p = new Node(x);
        if (head == nullptr)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

void DeleteRepeat (Node* head)
{
    int current = 0;
    Node* pre = nullptr;
    while (head)
    {
        if (head->data == current)
        {
            Node* temp = head;
            pre->next = head->next;
            head = head->next;
            delete temp;
        }
        else if (head->data > current)
        {
            current = head->data;
            pre = head;
            head = head->next;
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        Node* head = nullptr;
        if (n == 0)
            cout << "list is empty" << endl;
        else
        {
            head = CreateList(n);
            PrintList(head);
            DeleteRepeat(head);
            PrintList(head);
        }
    }
    return 0;
}