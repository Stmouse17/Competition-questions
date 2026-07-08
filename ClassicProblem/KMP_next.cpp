#include <iostream>
#include <vector>
#include <string>
using namespace std;

//KMP/Leetcode style/Cpp version

void getNext(string pattern, vector<int>& next)
{
    int m = pattern.size();
    next.resize(m);
    //set the length of the next array to the length of the pattern string
    //next:[0, 0, 0, 0, 0]
    next[0] = 0;
    int j = 0;  //length of the current longest common prefix-suffix
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = next[j - 1];    //Core code
        if (pattern[i] == pattern[j])
            j++;
        next[i] = j;
    }
}

/*
Case
1.  There are absolutely no common prefixes or suffixes.
    A B C D E
    0 0 0 0 0
2.  All identical characters
    A A A A A
    0 1 2 3 4
3.  Classic examples from the textbook
    A B A B C
    0 0 1 2 0
4.  Continuous rollback
    A B A B A C A
    0 0 1 2 3 0 1
5.  Examples of research papers
    A B C D A B D
    0 0 0 0 1 2 0
regular pattern:
*Incremental growth
*when pairing is lost, it can only drop to 0 or 1
*/

int KMP(string s, string p)
{
    vector<int> next;
    getNext(p, next);
    int j = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != p[j])
            j = next[j - 1];
        if (s[i] == p[j])
            j++;
        if (j == p.size())
            return i - p.size() + 1;
    }
    return -1;
}

int main()
{
    string s = "ABABCABABD";
    string p = "ABABD";
    cout << KMP(s, p);
    return 0;
}
