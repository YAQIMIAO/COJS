#include <stdio.h>

int main() {
    int p,q,l,r,i,j,len,n;
    int a[50],b[50],c[50],d[50];
    scanf("%d %d %d %d",&p,&q,&l,&r);
    for (i=0;i<p;++i) {
        scanf("%d %d",&a[i],&b[i]);
    }
    for (i=0;i<q;++i) {
        scanf("%d %d",&c[i],&d[i]);
    }
    n = 0;
    for (len=l; len<=r; ++len) {
        i = 0;
        j = 0;
        while (i<p && j<q) {
            if (a[i]  > d[j] + len) {++j;}
            else if (b[i] < c[j] + len) {++i;}
            else {
                ++n;
                break;
            }
        }
    }
    printf("%d\n",n);
    return 0;
}