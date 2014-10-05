#include <stdio.h>


int main() {
	//FILE *inp=NULL;
	//FILE *out=NULL;
	//inp=fopen("ts.in","r");
	//out=fopen("ts.out","w");
	long long n,m,a;
	fscanf(stdin,"%I64d %I64d %I64d",&n,&m,&a);
	if (n%a>0) {
		n=n/a+1;
	} else {
		n=n/a;
	}
	if (m%a>0) {
		m=m/a+1;
	} else {
		m=m/a;
	}
	fprintf(stdout,"%I64d\n",n*m);
	//fclose(inp);
	//fclose(out);
	return 0;
}
