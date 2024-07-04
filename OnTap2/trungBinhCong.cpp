#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int arr[5];
    
    for (int i = 0; i<5; i++) {
        cin >> arr[i];
    }
    
    double sum = 0;
    for (int i = 0; i<5; i++) {
        sum += arr[i];
    }
    
    cout << fixed << setprecision(2) << sum / 5 << endl;
     
    return 0;
}
