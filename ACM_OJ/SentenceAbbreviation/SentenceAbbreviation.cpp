#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

//Principle: The stream string ends when it encounters a space

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string word;
        while (ss >> word)
            cout << (char)toupper(word[0]);
        cout << endl;
    }
    return 0;
}