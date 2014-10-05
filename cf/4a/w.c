#include <stdio.h>

int main() {
	FILE *inp=NULL;
	FILE *out=NULL;
	//inp=fopen("w.in","r");
	//out=fopen("w.out","w");
	inp=stdin;
	out=stdout;
	int w;
        fscanf(inp,"%d", &w);
        if (w>2 && w%2==0) {
                fprintf(out,"YES\n");
        } else {
                fprintf(out,"NO\n");
        }
	//fclose(inp);
	//fclose(out);
	return 0;
}

