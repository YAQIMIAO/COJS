#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    cout << ((s.size() < t.size()) ? "no" : "go");
}