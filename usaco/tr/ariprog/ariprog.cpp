/* AC
    sort and optimized enumeration procedure*/
/*
ID: fooloo1
PROG: ariprog
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

#define rep(i,a,b) for(i=a;i<b;++i)
long s[32000];
long a[2000],b[2000],o[2000];
int fseq(long s[],long a,long b,long n);
long rmrp(long s[],long l);

int compare (const void * p, const void * q)
{
  return ( *(long*)p - *(long*)q );
}

int compare2 (const void *p, const void *q) {
    if (b[*(long*)p]<b[*(long*)q]) return -1;
    else if (b[*(long*)p]==b[*(long*)q] && a[*(long*)p]<a[*(long*)q]) return -1;
    return 1;
}

int main() {
    ofstream fout ("ariprog.out", ios::out);
    ifstream fin ("ariprog.in", ios::in);
    long n,m,i,j,len_s,flag;
    long num[250000]={0};
    fin >> n >> m;
    /** gen set S*/
    rep(i,0,m+1) rep(j,i,m+1) {
        s[(2*m-i+1)*(i)/2+j]=pow(i,2)+pow(j,2);
        num[s[(2*m-i+1)*(i)/2+j]]=1;
    }
    len_s=(m+1)*(m+2)/2;
    /** sort S*/
    qsort(s,len_s,sizeof(long),compare);
    /** cut out repetition in S*/
    len_s=rmrp(s,len_s);
    /** enumerate all possible a=s[i] and b=s[j]-s[i]
       * optimized procedure: important one is s[i]+(s[j]-s[i])*(n-2)<s[len_s-1]*/
    flag=0;
    rep(i,0,len_s-n+1) rep(j,i+1,len_s-n+2) {
        if (s[i]+(s[j]-s[i])*(n-2)<s[len_s-1] && fseq(num,s[i],s[j]-s[i],n)) {
            a[flag]=s[i];
            b[flag]=s[j] - s[i];
            o[flag]=flag;
            flag++;
        }
    }
    qsort(o,flag,sizeof(long),compare2);
    if (flag==0) 
        fout << "NONE" << endl;
    else
        rep(i,0,flag) fout << a[o[i]]  << " " << b[o[i]] << endl;
    return 0;
}

int fseq(long num[],long a,long b,long n) {
    long i;
    for (i=1;i<n;++i) if (! num[a+i*b]) return 0;
    return 1;
}

long rmrp(long s[],long l) {
    long i,length,lastlong;
    length=0;
    lastlong=s[0];
    for (i=1;i<l;i++)
        if (lastlong!=s[i]) {
            ++length;
            s[length]=s[i];
            lastlong=s[i];
        } 
    return length+1;
}