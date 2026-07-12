#include <iostream>
#include <string>
using namespace std;

//do not forget the computer scientists' quest for optimization

void PostOrder(string pre, string in)
{
    if (pre.empty())
        return;
    char root = pre[0];
    int pos = in.find(root);
    PostOrder(pre.substr(1, pos), in.substr(0, pos));
    PostOrder(pre.substr(pos + 1), in.substr(pos + 1));
    cout << root;
}

int main()
{
    string pre, in;
    while (cin >> pre >> in)
    {
        PostOrder(pre, in);
        cout << endl;
    }
    return 0;
}