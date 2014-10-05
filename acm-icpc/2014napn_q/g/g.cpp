#include <iostream>
#include <math.h>
using namespace std;

void body();
int mosqinbow(double cx, double cy, double x[], double y[], int n, int m1, int m2,double r);
int max(int a, int b);
double dist(double x1,double y1,double x2,double y2);

int main() {
    int n,i;
    cin>>n;
    for (i=0;i<n;++i) {
        body();
    }
}

void body() {
    int n,i,j,maxm;
    double r,x[100],y[100],mx,my,d,h,sintheta,costheta,c1x,c1y,c2x,c2y;
    cin>>n;
    cin>>r;
    r=r/2;
    for (i=0;i<n;++i) {
        cin>>x[i]>>y[i];
    }
    maxm=0;
    for (i=0;i<n-1;++i) 
        for (j=i+1;j<n;++j) { //i,j have to be different
            d=dist(x[i],y[i],x[j],y[j]);
            if (d>r*2) continue;
            mx=(x[i]+x[j])/2;
            my=(y[i]+y[j])/2;
            h=sqrt(pow(r,2)-pow(d/2,2));
            sintheta=(y[j]-y[i])/d;
            costheta=(x[j]-x[i])/d;
            c1x=mx-sintheta*h;
            c2x=mx+sintheta*h;
            c1y=my+costheta*h;
            c2y=my-costheta*h;
            maxm=max(maxm, mosqinbow(c1x,c1y,x,y,n,i,j,r));
            maxm=max(maxm, mosqinbow(c2x,c2y,x,y,n,i,j,r));
        }
    if (maxm==0) {cout<<1<<endl;return;}
    cout<<maxm<<endl;
    return;
}

int mosqinbow(double cx, double cy, double x[], double y[], int n, int m1, int m2,double r) {
    int i,cnt;
    cnt=2;
    for (i=0;i<n;++i) {
        if (i==m1 || i==m2) continue;
        if (dist(x[i], y[i],cx,cy)<=r) ++cnt;
    }
    return cnt;
}

int max(int a, int b) {
    if (a>b) return a;
    return b;
}

double dist(double x1,double y1,double x2,double y2) {
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}