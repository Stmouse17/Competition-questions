#include <iostream>
#include <string>
using namespace std; 

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void Show(Node*);
void Get(Node*, int);
bool Delete(Node* &, int);
bool Insert(Node* &, int, int);

int main()
{
    int n;
    cin >> n;
    Node* head = nullptr;   //no head node
    for (int i = 0; i < n; i++) //headinsert
    {
        int x;
        cin >> x;
        Node* p = new Node(x);
        p->next = head;
        head = p;
    }
    int m;
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        string op;
        cin >> op;
        //the switch statement can only be used with types such as integers,
        //characters, and enumerations; it cannot be used with strings
        if (op == "show")
            Show(head);
        //counting starts from 1
        else if (op == "get")
        {
            int a;  //get the a-th element
            cin >> a;
            Get(head, a);
        }
        else if (op == "delete")
        {
            int a;  //delete the a-th element
            cin >> a;
            if (Delete(head, a))
                cout << "delete OK" << endl;
            else
                cout << "delete fail" << endl;
        }
        else if (op == "insert")
        {
            int a, e;   //insert e before the a-th position
            cin >> a >> e;
            if (Insert(head, a, e))
                cout << "insert OK" << endl;
            else
                cout << "insert fail" << endl;
        }
    }
    return 0;
}

void Show(Node* head)
{
    if (head == nullptr)
    {
        cout << "Link list is empty" << endl;
        return;
    }
    while (head)
    {
        cout << head->data;
        if (head->next) //detail(>~<)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

void Get(Node* head, int pos)
{
    int current = 1;
    while (head)
    {
        if (current == pos)
        {
            cout << head->data << endl;
            return;
        }
        current++;
        head = head->next;
    }
    cout << "get fail" << endl;
}

bool Delete(Node* &head, int pos)
{
    if (head == nullptr)    //empty list
        return false;
    if (pos == 1)           //delete the first node
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    Node* pre = head;
    Node* current = head->next;
    int index = 2;
    while (current)
    {
        if (index == pos)
        {
            pre->next = current->next;
            delete current;
            return true;
        }
        pre = current;
        current = current->next;
        index++;
    }
    return false;
}

bool Insert(Node* &head, int pos, int e)
{
    if (pos == 1)
    {
        Node* p = new Node(e);
        p->next = head;
        head = p;
        return true;
    }
    Node* pre = head;
    int index = 2; 
    while (pre)
    {
        if (index == pos)
        {
            Node* p = new Node(e);
            p->next = pre->next;
            pre->next = p;
            return true;
        }
        index++;
        pre = pre->next;
    }
    return false;
}






