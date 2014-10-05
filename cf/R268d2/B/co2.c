/** try out another slightly shorter solution.
  *  Notice: this algortihm takes more memory and more time especially
  *  for the case that p and q are small. but it's shorter.
  *  be careful about boundaries. */
#include <stdio.h>
#define rep(i,a,n) for(i=a;i<n;i++)


int main() {
    int p,q,l,r,i,j,lt,rt,ans;
    int a[2001] = {0}, b[2001] = {0};
    scanf("%d %d %d %d",&p,&q,&l,&r);
    rep(i,0,p) {scanf("%d%d",&lt,&rt);rep(j,lt,rt+1) a[j]=1;}
    rep(i,0,q) {scanf("%d%d",&lt,&rt);rep(j,lt,rt+1) b[j]=1;}
    ans=0;
    rep(i,l,r+1) rep(j,i,1001) if (a[j] & b[j-i]) {ans+=1; break;}
    printf("%d\n",ans);
    return 0;
}
