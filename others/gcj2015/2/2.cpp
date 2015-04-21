#include <iostream>

using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

void ihp(int num) {
    int d, i, n, m, t, half, flag;
    int p[1005] = {};
    int f[1005] = {};
    int g[1005] = {};
    cin >>d;
    m = 0;
    t = 0;
    flag = 0;
    for (i = 0; i < d; i++) {
        cin >>n;
        p[n]++;
        if (n > m) m = n;
    }
    if (m <=3) {
        cout << "Case #"<<num<<": "<<m<<endl;
        return;
    }
    f[m+1] = 0;
    g[m+1] = m;
    for (i = m; i > 1; i--) {
        if (p[i] == 0) {
            f[i] = f[i+1];
            g[i] = g[i+1];
            continue;
        }
        g[i] = min(f[i+1] + i, g[i+1]);
        half = i /2;
        p[half] += p[i];
        p[i - half] += p[i];
        f[i] = f[i+1] + p[i];
        // cout << i << ": " << "g=" <<g[i] << "f="<<f[i] << endl;
    }
    cout << "Case #"<<num<<": "<<min(g[2], f[2] + 1)<<endl;
}

int main() {
    int t, i;
    cin >>t;
    for (i = 0; i< t; i++) {
        ihp(i+1);
    }
}