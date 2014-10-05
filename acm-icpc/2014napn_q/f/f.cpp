#include <iostream>
using namespace std;

int main() {
    long n,d,a,b;
    cin >>n >>d;
    while (n!=0 && d!=0) {
        b=n % d;
        a=(n-b)/d;
        cout <<a <<" "<<b<<" / "<<d<<endl;
        cin >>n >>d;
    }
    return 0;
}