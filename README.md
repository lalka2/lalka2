# lalka2
data
#include <iostream>

using namespace std;

struct kek {
    char name[25];
    double d;
    double mass;

    void print() {
        cout << name << "\n" << d << "\n" << mass << endl;
    }

};

int main() {
    pizza *ps = new kek;
    cout << "Enter company name:";
    cin.getline(ps->name, 25);
    cout << "Enter kek diameter:";
    cin >> ps->d;
    cout << "Enter kek mass:";
    cin >> ps->mass;
    ps->print();
    return 0;
}
