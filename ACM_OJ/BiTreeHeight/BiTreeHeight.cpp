#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pre, in;

//preL: starting index of the left subtree in the (string pre)
//preR: end index of the left subtree in the (string pre)
//inL: end index of the left subtree in the (string in)
//inR: starting index of the left subtree in the (string in)

int Height(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return 0;           //the height of an empty tree is 0
    char root = pre[preL];  //root of subtree for this stack frame 
    int k = inL;            
    while (in[k] != root)
        k++;                //root index in (string in)
    int leftsize = k - inL; //length of the left subtree for this stack frame
    int leftHeight = Height(preL + 1, preL + leftsize, inL, k - 1);
    /*  
        implicit termination condition:
        the left and right subtrees of a leaf node are both empty,
        so leftsize == 0. Falling into recursion involving null nodes
        (new preL == original preL + 1) > (new preR == original preL + leftsize(0))  
    */
    int rightHeight = Height(preL + leftsize + 1, preR, k + 1, inR);
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cin >> pre >> in;
        cout << Height(0, n - 1, 0, n - 1) << endl;
    }
    return 0;
}