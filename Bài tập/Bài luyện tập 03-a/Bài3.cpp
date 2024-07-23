#include <iostream>
using namespace std;

void recursiveBinary(int n, string s) {
    if (n == 0) {
        cout << s << endl;
    } else {
        recursiveBinary(n - 1, s + '0');
        recursiveBinary(n - 1, s + '1');
    }
}

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n > 10) {
        return 1;
    }

    recursiveBinary(n, "");

    return 0;
}
