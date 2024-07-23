struct Rectangle {
    // your code goes here
    // Cac bien thanh vien
    int height, length;
    // your code goes here
    // Hai ham khoi tao
    Rectangle() {
        height = 0;
        length = 0;
    }

    Rectangle(int _h, int _l) {
        height = _h;
        length = _l;
    }
    int getPerimeter() {
        // your code goes here
        return 2*(height + length);
    }

    void print() {
        // your code goes here
        for (int i = 0; i<length; i++) {
            cout << "*";
        }
        cout << endl;
        for (int i = 1; i < height - 1; i++) {
            cout << "*";
            for (int j = 1; j<length - 1; j++) {
                cout << " ";
            }
            if (length > 1) {
                cout <<"*";
            }
            cout << endl;
        }
        if (length > 1) {
            for (int i = 0; i<length; i++) {
                cout <<"*";
            }
            cout << endl;
        }
    }
};

int compare(Rectangle a, Rectangle b) {
    // your code goes here
    int perimeterA = a.getPerimeter();
    int perimeterB = b.getPerimeter();
    if (perimeterA == perimeterB) return 0;
    if (perimeterA > perimeterB) return -1;
    return 1;
}
