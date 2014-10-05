#include "contest.h"
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double k;
    long r,n,d;
    while (cin>>k) {
        r = sqrt(2*k);
        d = k - (r-1)*r/2;
        while (d>r) {
            d-=r;
            ++r;
        }
        while (d<0) {
            d+=r;
            --r;
        }
        printf("%.0lf",k);
        cout<<" => "<<r+1-d<<"/"<<d<<endl;
    }
    exit(0);
}