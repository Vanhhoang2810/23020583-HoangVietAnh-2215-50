class Box{
    private:
        int l, b, h;
    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }
        Box (int _l, int _b, int _h) {
            l = _l;
            b = _b;
            h = _h;
        }
        Box(const Box& B) {
            l = B.l;
            b = B.b;
            h = B.h;
        }
        int getLength() {
            return l;
        }
        int getBreadth() {
            return b;
        }
        int getHeight() {
            return h;
        }
        long long CalculateVolume(){
            return (long long)l*b*h;
        }
        friend bool operator < ( Box& A, Box& B) {
            if ((A.l<B.l) || ((A.b < B.b) && (A.l == B.l)) || ((A.h < B.h) && (A.b == B.b) && (A.l == B.l))) {
                return true;
            } else {
                return false;
            }
        }

        friend ostream& operator << (ostream& out, const Box& B) {
            out << B.l << " " << B.b << " " << B.h;
            return out;
        }
};
