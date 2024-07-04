#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                 "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
                 "eighteen", "nineteen"};

string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string convert_hundreds(int n) {
    string result = "";
    if (n >= 100) {
        result += ones[n / 100] + " hundred";
        n %= 100;
    }
    if (n >= 20) {
        if (!result.empty()) result += " ";
        result += tens[n / 10];
        if (n % 10 > 0) result += "-" + ones[n % 10];
    } else if (n > 0) {
        if (!result.empty()) result += " ";
        result += ones[n];
    }
    return result;
}

string convert_thousands(int n) {
    string result = "";
    if (n >= 1000) {
        result += convert_hundreds(n / 1000) + " thousand";
        n %= 1000;
    }
    if (n > 0) {
        if (!result.empty()) result += " ";
        result += convert_hundreds(n);
    }
    return result;
}

string convert_millions(int n) {
    string result = "";
    if (n >= 1000000) {
        result += convert_hundreds(n / 1000000) + " million";
        n %= 1000000;
    }
    if (n > 0) {
        if (!result.empty()) result += " ";
        result += convert_thousands(n);
    }
    return result;
}

string numberToWords(int num) {
    if (num == 0) return "zero";
    string result = "";
    if (num < 0) {
        result += "negative ";
        num = -num;
    }
    result += convert_millions(num);
    return result;
}

int main() {
    int num;
    cin >> num;
    cout << numberToWords(num) << endl;
    return 0;
}
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
