#include <iostream>

using namespace std;

void body() ;

int main() {
    int t,i;
    cin >> t;
    for (i=0;i<t;++i) {
        body();
    }
    return 0;
}

void body() {
    long n, d, i, len;
    double v, f, c;
    cin >> n >> d;
    len=0;
    for (i=0;i<n;++i) {
        cin >> v >> f >> c;
        if (d*c/v <= f) ++len;
    }
    cout << len << endl;
}