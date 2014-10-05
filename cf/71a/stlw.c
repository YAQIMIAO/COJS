#include <stdio.h>
#include <string.h>

int main() {
        FILE *in =  NULL;
        FILE *out = NULL;
        in = fopen("wtlw.in", "r");
        out = fopen("wtlw.out", "w");
        int n;
        char a[100][255];


        fclose(in);
        fclose(out);
        return 0;
}