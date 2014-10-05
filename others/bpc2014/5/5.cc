#include <iostream>
#include <string>
using namespace std;

int penalty(char c);
//int pen(int *sh, int *st, char *stack, char hand[3][], int h[], int c[], int p, int judge);

int main() {
    string card;
    char stack[52],hand[3][52],*tmp,judge,j1;
    int i,j,c[2],h[2],sc,p;
    //input
    for (i=0;i<26;++i) {
        cin>>card;
        hand[0][i]=card[1];
    }
    for (i=0;i<26;++i) {
        cin>>card;
        hand[1][i]=card[1];
    }
    //inital
    sc=0;
    h[0]=0;c[0]=26;
    h[1]=0;c[1]=26;
    p=0;
    //play
    while (c[p]>0) {
        cout<<hand[0]<<endl;
        cout<<hand[1]<<endl;
        judge=penalty(hand[p][h[p]]);
        stack[sc]=hand[p][h[p]];
        h[p]=(h[p]+1)%53;
        --c[p];
        sc++;
        if (judge==0) {p=1-p;continue;}
    //until penalty paid
        while (judge>0) {
            j1=0;
            while (judge>0) {
                if (c[1-p]==0) {judge=0;break;}
                stack[sc]=hand[1-p][h[1-p]];
                h[1-p]=(h[1-p]+1)%53;
                c[1-p]--;
                judge--;
                sc++;
                j1=penalty(stack[sc-1]);
                if (j1) break;
            }
            if (j1>0) {
                judge=j1;
                p=1-p;
            }
        }
        if (c[0]==0 || c[1]==0) break;
    //collect cards
        for (i=0;i<sc;++i){
            hand[p][(h[p]+c[p]+i)%53]=stack[sc];
        }
        c[p]=c[p]+sc;
        sc=0;
    }
    if (c[0]==0) cout<<c[1]<<endl;
    else cout<<c[0]<<endl;
    //until p1 or p2 empty print nonempty card number
}

int penalty(char c) {
    if (c=='J') return 1;
    if (c=='Q') return 2;
    if (c=='K') return 3;
    if (c=='A') return 4;
    return 0;
}

/*int pen(int *sh, int *st, char *stack, char **hand, int h[], int c[], int p, int judge) {
    int j1;
    while (judge>0 && c[1-p]!=0) {
        if (c[1-p]==0) return p;
        j1=penalty(hand[1-p][h[1-p]]);
        stack[*st]=hand[1-p][h[1-p]];
        h[1-p]=(h[1-p]+1)%53;
        c[1-p]--;
        judge--;
        *st=(*st+1)%53;
        if (j1) break;
    }
    if (j1) return pen(sh,st,stack,hand,h,c,1-p,j1);
    return p;
}*/