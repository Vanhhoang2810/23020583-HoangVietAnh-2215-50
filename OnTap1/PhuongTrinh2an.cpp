#include <iostream>
#include <cmath>

using namespace std;

void hePhuongTrinh(int a1, int a2, int b1, int b2, int c1, int c2) {
    float D = a1*b2 - a2*b1;
    float Dx = c1*b2 - c2*b1;
    float Dy = c2*a1 - c1*a2;
    
    if (D==0) {
        if (Dx == 0 && Dy == 0) {
            cout << "Vo so nghiem";
        } else {
            cout << "Vo nghiem";
        }
    } else {
        float x = Dx/D;
        float y = Dy/D;
        cout << "x = " << x << ", y = " << y; 
    }
}

int main() {
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    hePhuongTrinh(a1, a2, b1, b2, c1, c2);
    
    return 0;
}
