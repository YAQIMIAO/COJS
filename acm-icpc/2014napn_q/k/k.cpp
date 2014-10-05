//geometric problem: unsolved.
#include <iostream>
#include <math.h>

using namespace std;

void body();

int main() {
    int n,i,t;
    cin >>n;
    for (i=0;i<n;++i) {
        cout<<i<<endl;
        body();
    }
    return 0;
}

void body() {
    int i,j,k,n;
    double m,b,d,t,st,ct,at,d1,d2,bike,tmp;
    cin>>m; //cout<<m;
    cin>>b;
    cin>>d;
    cin>>t;
    //where is the cyclists when Max reach the line.
    d1 = b*(5/m + t);
    if (d1 < d) {cout<<"Max beats the first bicycle"<<endl;return;} //problemetic condition
    //when coc reach the line
    tmp = d1 - d;
    d2 = b*(5.5/m + t);
    bike = 1;
    while (tmp>4) {
        ++bike;
        tmp = tmp - 4;
        d2 -= 4;
    }
    if (d2>=-0.5) cout<<"Collision with bicycle "<<bike<<endl;

}