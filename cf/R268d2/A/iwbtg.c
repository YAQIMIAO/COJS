#include <stdio.h>

int main() {
    int n,p,q,i,t;
    int a[100] = {0};
    scanf("%d",&n);
    scanf("%d",&p);
    for (i = 0;i < p; ++i) {
        scanf("%d",&t);
        a[t - 1] = 1;
    }
    scanf("%d",&q);
    for (i = 0;i < q; ++i) {
        scanf("%d",&t);
        a[t - 1] = 1;
    }
    for (i = 0;i < n; ++i) {
        if (a[i] == 0) {
            printf("%s","Oh, my keyboard!\n");
            return 0;
        } 
    }
    printf("%s","I become the guy.\n");
    return 0;
}