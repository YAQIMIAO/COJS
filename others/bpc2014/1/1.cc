#include "contest.h"
//#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

char code(char c);
char decode(char c, int dl);

int main() {
    string cypher,word;
    //char cypher[1000],word[1000];
    int i,j,flag,l,n,dl;
    while (getline(cin, cypher)) {
        l=cypher.length();
        getline(cin, word);
        n=word.length();
        for (i=0;i<l-n;++i){
            dl=(code(cypher[i])-code(word[0])) % 27;
            flag=0;
            for (j=0;j<n;++j){
                if ((code(cypher[i+j])-code(word[j])) % 27!=dl){
                    flag=1;
                    break;
                }
            }
            if (flag==0) break;
        }
        if (dl<0) dl+=27;
        for (i=0;i<l-1;++i) {
            cout<<decode(cypher[i], dl);
        }
        cout<<"."<<endl;
    }
    exit(0);
}

char code(char c) {
    if (c==' ') return 'Z'+1;
    return c;
}

char decode(char c, int dl) {
    c=code(c);
    c=(c-'A'-dl);
    if (c<0) c+=27;
    c='A'+c;
    if (c=='Z'+1) return ' ';
    return c;
    //else return ' ';
}