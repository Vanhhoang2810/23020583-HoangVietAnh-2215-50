#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    private:
        int age, standard;
        string first_name, last_name;
    public:
        void set_age(int a) {
            age = a;
        }
        int get_age() {
            return age;
        }
        void set_first_name(string b) {
            first_name = b;
        }
        string get_first_name() {
            return first_name;
        }
        void set_last_name(string c) {
            last_name = c;
        }
        string get_last_name() {
            return last_name;
        }
        void set_standard(int d) {
            standard = d;
        }
        int get_standard() {
            return standard;
        }
        string to_string() {
            stringstream var;
            var << age << "," << first_name << "," << last_name << "," << standard;
            return var.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}
