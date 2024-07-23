#include <iostream>
using namespace std;

void recursiveBinary(int n, int m, string s) {
    if (n == 0 && m == 0) {
        cout << s << endl;
    } else {
        if (n>0) {
            recursiveBinary(n - 1, m, s + '0');
        }
        if (m>0) {
            recursiveBinary(n, m - 1, s + '1');
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    recursiveBinary(n, m, "");
    return 0;

}
