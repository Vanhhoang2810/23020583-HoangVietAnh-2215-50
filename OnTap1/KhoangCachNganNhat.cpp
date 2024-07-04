#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n; 
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int min = abs(arr[1] - arr[0]);
    
    for(int i = 0; i<n; i++) {
        int distance = abs(arr[i] - arr[i - 1]);
        if (distance < min) {
            min = distance;
        }
    }
    
    cout << min;
    return 0;
}
