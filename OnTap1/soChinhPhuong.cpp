#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (sqrt(n) * sqrt(n) == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
