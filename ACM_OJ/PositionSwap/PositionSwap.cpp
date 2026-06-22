#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        for (int j = 0; j < word.length(); j += 2)
        {
            char temp, pos_odd, pos_even;
            temp = word[j];
            word[j] = word[j + 1];
            word[j + 1] = temp;
        }
        cout << word << endl;
    }
    return 0;
}

