#include <iostream>
using namespace std;

struct Node
{
    char data;
    int left, right;
};

Node tree[105];

void PreOrder(int root)
{
    if (root == 0)
        return;
    cout << tree[root].data;
    PreOrder(tree[root].left);
    PreOrder(tree[root].right);
}

void InOrder(int root)
{
    if (root == 0)
        return;
    InOrder(tree[root].left);
    cout << tree[root].data;
    InOrder(tree[root].right);
}

void PostOrder(int root)
{
    if (root == 0)
        return;
    PostOrder(tree[root].left);
    PostOrder(tree[root].right);
    cout << tree[root].data; 
}

int main()
{
    int n;
    cin >> n;
    bool child[105] = { false };
    for (int i = 1; i <= n; i++)
    {
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        tree[i].data = ch;
        tree[i].left = l;
        tree[i].right = r;
        if (l != 0)
            child[l] = true;
        if (r != 0)
            child[r] = true;
    }
    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!child[i])
        {
            root = i;
            break;
        }
    }
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}

