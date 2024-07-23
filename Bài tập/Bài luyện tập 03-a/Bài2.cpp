#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int left, int right, int arr[], int value) {
    if (left > right) {
        return false;
    }
    int mid = (left + right) / 2;
    if (arr[mid] == value) {
        return true;
    }
    if (arr[mid] < value) {
        return binarySearch(mid + 1, right, arr, value);
    } else {
        return binarySearch(left, mid - 1, arr, value);
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    int arr[m], arrs[n];
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> arrs[j];
    }

    sort(arr, arr + m);

    for (int j = 0; j < n; j++) {
        if (binarySearch(0, m - 1, arr, arrs[j])) {
            cout << "YES ";
        } else {
            cout << "NO ";
        }
    }
    cout << endl;

    return 0;
}
