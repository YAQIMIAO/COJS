//单组数据都能过，连续多组数据就过不了。
//单组可以过说明应该不会是程序本身或者输入输出的问题。
//或许和数组初始化有关？反复利用就不行之类。
#include <iostream>
#include <string>
using namespace std;

int penalty(int n);
string card;
int stack[53],player[2][100],i,j,h[2],c[2],sc,p,pen,penpen;

int main() {
while (1) {
    for (j=0;j<2;++j)
    for (i=0;i<26;++i) {
        if (cin>>card) {}
        else {exit(0);}
        if (card[1]>'1' && card[1]<='9') player[j][i]=card[1]-'0';
        if (card[1]=='T') player[j][i]=10;
        if (card[1]=='J') player[j][i]=11;
        if (card[1]=='Q') player[j][i]=12;
        if (card[1]=='K') player[j][i]=13;
        if (card[1]=='A') player[j][i]=14;
    }
    c[0]=26;c[1]=26;
    sc=0;p=0;
    while (c[0]>0 && c[1]>0) {
        stack[sc]=player[p][h[p]];
        h[p]=h[p]+1;
        c[p]--;
        sc++;
        pen=penalty(stack[sc-1]);
        if (pen==0) {p=1-p;continue;}
        while (pen>0) {
            if (c[1-p]==0) {
                break;
            }
            while (pen>0) {
                if (c[1-p]==0) {
                    break;
                }
                stack[sc]=player[1-p][h[1-p]];
                h[1-p]=h[1-p]+1;
                c[1-p]--;
                sc++;
                pen--;
                penpen=penalty(stack[sc-1]);
                if (penpen==0) continue;
                pen=penpen;
                p=1-p;
                break;
            }
        }
        if (c[p]==0 || c[1-p]==0) break;
    //collect cards
        if (c[1-p]>0) {
            for (i=0;i<sc;++i) {
                player[p][h[p]+c[p]+i]=stack[i];
            }
            c[p]+=sc;
            sc=0;
            //cout<<c[0]<<endl;
        }
    }
    if (c[0]==0) cout<<c[1]<<endl;
    else cout<<c[0]<<endl;
}
    exit(0);
}

int penalty(int n) {
    if (n<=10) return 0;
    return n-10;
}