#include <iostream>

using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void positive() {
    cout << "Case #"<<num<<": "<<"GABRIEL"<<endl;
}

void negative() {
    cout << "Case #"<<num<<": "<<"RICHARD"<<endl;
}

void oo(int num) {
    int x, r, c;
    cin >>x>>r>>c;
    if ((r*c) % x != 0 || x > max(r, c) || x/2 > min(r, c)) {
        negative();
        return;
    }
    if (min)
}

int main() {
    int t, i;
    cin >> t;
    for (i = 1; i <= t; i++) {
        oo(i);
    }
    exit(0);
}