#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    double num;
    double min, max;
    
    cin >> num;
    min = max = num;
    
    for (int i = 0; i<n; i++) {
        cin >> num;
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }
    
    cout << max << endl;
    cout << min;
    return 0;
}
