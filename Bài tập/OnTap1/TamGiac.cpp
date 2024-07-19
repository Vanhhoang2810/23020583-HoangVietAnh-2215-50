#include <iostream>
#include <vector>
using namespace std;

void DistinctNumbers(const vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    
    cout << arr[0];
    
    for (size_t i = 1; i<arr.size(); i++) {
        if (arr[i] != arr[i - 1]) {
            cout << " " << arr[i];
        }
    }
}

int main() {
    vector<int> arr;
    int num;
    
    while(cin>> num && num>+0) {
        arr.push_back(num);
    }
    
    if (!arr.empty()) {
        DistinctNumbers(arr);
        cout << " ";
    }
    
    cout << num << endl;
    
    return 0;
}
