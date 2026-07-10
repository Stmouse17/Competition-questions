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

Node* CreateList(int n) //base on tailinsert
{
    Node* head = nullptr;
    Node* tail = nullptr;
    //maintain a tail pointer to reduce the overhead of
    //traversing to the end each time
    for (int i = 0; i < n; i++)
    {
        int x;
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

Node* ReverseList(Node* head)
{
    Node* pre = nullptr;
    Node* cur = head;
    while (cur != nullptr)
    {   
        //3 pointer
        Node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void DestroyList(Node* head)
{
    while (head)
    {
        Node* p = head;
        head = head->next;
        delete p;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << "list is empty" << endl;
            continue;
        }
        Node* head = CreateList(n);
        PrintList(head);
        head = ReverseList(head);
        PrintList(head);
        DestroyList(head);
    }
    return 0;
}





