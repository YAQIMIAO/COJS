//Qsort in cpp
#include <stdlib.h>
#include <stdio.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {
    FILE *INP=NULL;
    INP=fopen("qsort.in","r");
    FILE *OUT=NULL;
    OUT=fopen("qsort.out","w");
    int n,i;
    fscanf(INP,"%d",&n);
    int a[100];
    for (i=0;i<n;++i) {
        fscanf(INP,"%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compare);
    for (i=0;i<n;++i) {
        fprintf(OUT,"%d ",a[i]);
    }
    fprintf(OUT,"\n");
    fclose(INP);fclose(OUT);
    return 0;
}