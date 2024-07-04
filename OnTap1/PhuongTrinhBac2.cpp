#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void quadratic(int a, int b, int c) {
    int delta = pow(b,2) - 4*a*c;
    
    if (delta > 0) {
        double x1 = (-b + sqrt(delta))/(2*a);
        double x2 = (-b - sqrt(delta))/(2*a);
        if (x1>x2) swap(x1, x2);
        cout << fixed << setprecision(2) << x1 << endl;
        cout << fixed << setprecision(2) << x2 << endl;
    } else if (delta == 0) {
        double x = -b / (2*a);
        cout << fixed << setprecision(2) << x << endl;
    } else if (delta < 0) {
        double real = (double)-b / (2*a);
        double fake = sqrt(-delta) / (2 * a);
        cout << fixed << setprecision(2) << real << " " << fixed << setprecision(2) << -fake << endl;
        cout << fixed << setprecision(2) << real << " " << fixed << setprecision(2) << fake << endl;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    quadratic(a, b, c);
}
