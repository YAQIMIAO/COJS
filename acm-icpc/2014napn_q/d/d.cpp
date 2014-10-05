#include <iostream>
using namespace std;

void body();
int press(int bot, int state);
void query();
int min(int a,int b);

int a[512],v[512];

int main () {
    int p,i;
    for (i=0;i<513;++i) {
        v[i]=0;
        a[i]=5000;
    }
    v[0]=0;
    body();
    cin >>p;
    for (i=0;i<p;++i) {
        //input-->state;
        query();
    }
}

int min(int a,int b) {
    if (a<b) return a;
    return b;
}

void body() {
    //a[state1] = min (a[state1], a[statei]+1);
    int que[600],h,t,cstate,s,nstate,i;
    a[0]=0;
    h=0;t=0;
    que[h]=0;
    while (h<=t) {
        cstate=que[h];
        if (! v[cstate])
        for (i=0; i<9;++i) {
            nstate=press(i,cstate);
            s=a[nstate];
            a[nstate]=min(a[nstate], a[cstate]+1);
            if (s>a[nstate]){
                ++t;
                que[t]=nstate;
            }
        }
        v[cstate]=1;
        ++h;
    }
}

int press(int bot, int state) {
    //checked v
    state=state xor(1<<bot);
        //left bot%3>0
    if (bot%3>0) {
        state=state xor (1 << (bot-1));
    }
    //up
    if (bot/3>0) {
        state=state xor (1 << (bot-3));
    }
    //down
    if (bot/3<2) {
        state=state xor (1 << (bot+3));
    }
    //right
    if (bot%3<2) {
        state=state xor (1 << (bot+1));
    }
    return state;
}

void query(){
    //read input --> state, print a[state]
    int i,s;
    char c;
    s=0;
    for (i=0;i<9;++i) {
        cin >>c;
        if (c=='*') s=s | (1 << i);
    }
    cout <<a[s]<<endl;
}