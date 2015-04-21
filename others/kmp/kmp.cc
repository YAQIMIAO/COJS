#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void body(char *s, char *t);
int *getnext(char *t);
int kmp(char *s, char *t, int *next);

int main() {
    char s[1000],t[1000];
    int i,j;
    fgets(s, sizeof(s), stdin);
    if (s[strlen(s)-1]=='\n') s[strlen(s)-1] = '\0';
    fgets(t, sizeof(t), stdin);
    if (t[strlen(t)-1]=='\n') t[strlen(t)-1] = '\0';
    body(&s[0],&t[0]);
}

void body(char *s, char *t) {
    cout<<s<<endl;
    cout<<t<<endl;
    //get next[j]
    int *next, i;
    next = getnext(t);
    //kmp
    i = kmp(s, t, next);
    //output
    cout<<i<<endl;
}

int *getnext(char *t) {
    int *next = (int *) calloc(5, sizeof(int)); // {-1, 0, 1, 2, 3};
    /*next[0] = -1;
    for (int i=1; i<5; ++i) {
        next[i] = next[i-1]+1;
    }
    return next;*/
    //to be continued: http://blog.csdn.net/fangfully/article/details/18189905

}

int kmp(char *s, char *t, int *next) {
    int i,j;
    i = 0; j = 0;
    while (i<strlen(s) && j<strlen(t)) {
        if (s[i]==t[j]) {
            ++i; ++j;
        } else {
            if (j==0) {
                ++i;
            } else {
                j = next[j];
            }
        }
    }
    free(next);
    if (j==strlen(t)) return i-j;
    return -1;
}