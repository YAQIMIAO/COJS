#include <iostream>
#include <cstring>

using namespace std;

struct date {
    string month;
    int d, y;
};

int month(char* m) {
    if (strcmp(m, "January") == 0) {
        return 1;
    }
}

void test(int t) {
    date st, ed;
    cin >> st.month >> st.d >> st.y;
    cout << st.month << st.d << st.y;
}


int main() {
    int T, i;
    cin >> T;
    for (i = 0; i < T; i++) {
        test(i+1);
    }
    exit(0);
}