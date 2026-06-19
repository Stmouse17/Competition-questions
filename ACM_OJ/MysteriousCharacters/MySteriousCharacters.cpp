#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string lock, key; 
        cin >> lock >> key;
        int mid = lock.size() / 2;
        lock.insert(mid, key);
        cout << lock << endl;
    }
    return 0;
}