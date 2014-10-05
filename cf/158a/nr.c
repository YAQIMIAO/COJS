/** No qsort/sort needed for this problem. It says "The given sequence
 *   is non-increasing (that is, for all i from 1 to n - 1 the following
 *   condition is fulfilled: ai ≥ ai + 1)."
 *   Somehow adding qsort get WA when it runs on the oj, which works on
 *	this laptop. The test is:
 *	5 5
 *	1 1 1 1 1
 *	Expected output:
 *	5
 *	output on this laptop
 *	5
 *	output on oj(which runs on windows OS)
 *	0
 *	The reason could be qsort performes differently on each OS,
 *	or the oj limited memory so the qsort doesn't work.
 *	I still don't know why but next time READ PROBLEM DESCRIPTION
 *	CAREFULLY! */

#include <stdio.h>

int main() {
    FILE *inp=NULL;
    FILE *out=NULL;
    //inp=fopen("nr.in","r");
    //out=fopen("nr.out","w");
    inp=stdin;
    out=stdout;
    int n,k,i,j;
    int a[55];
    fscanf(inp,"%d %d",&n,&k);
    for (i=0;i<n;i++) {
        fscanf(inp,"%d", &a[i]);
    }
    //a[k]<=0
    if (a[k-1]<=0) {
        j=n-1;
        while (j>=0 && a[j]<=0) {
            --j;
        }
    } else {
    //a[k]>0
        j=n-1;
        while (a[j]<a[k-1]) {
            --j;
        }
    }
    fprintf(out,"%d\n",j+1);
    //fclose(inp);
    //fclose(out);
    return 0;
}
