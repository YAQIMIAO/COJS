#include <iostream>
#include <cstring>
using namespace std;

int clear(int ch[8][8], int x[], int y[]);

int main() {
    int i,j,chess[8][8],x[8],y[8],cnt;
    char c;
    cnt=0;
    for (i=0;i<8;++i) {
        for (j=0;j<8;++j) {
            cin >>c;
            if (c=='.') chess[i][j]=0;
            if (c=='*') {
                chess[i][j]=1;
                x[cnt]=i;
                y[cnt]=j;
                ++cnt;
            }
        }
    }
    if (cnt==8 && clear(chess, x,y)) cout << "valid" << endl;
    else cout << "invalid" << endl;
    return 0;
}

int clear(int ch[8][8], int x[], int y[]) {
    int p,i,j;
    for (p=0;p<8;++p) {
        //check x
        for (i=0;i<8;++i) {
            if (i==x[p]) continue;
            if (ch[i][y[p]]) return 0;
        }
        //check y
        for (i=0;i<8;++i) {
            if (i==y[p]) continue;
            if (ch[x[p]][i]) return 0;
        }
        //check diag
        i=x[p]-1;
        j=y[p]-1;
        while (i>=0 && j>=0) {
            if (ch[i][j]) return 0;
            --i;--j;
        }
        i=x[p]-1;
        j=y[p]+1;
        while (i>=0 && j<8) {
            if (ch[i][j]) return 0;
            --i;++j;
        }
        i=x[p]+1;
        j=y[p]+1;
        while (i<8 && j<8) {
            if (ch[i][j]) return 0;
            ++i;++j;
        }
        i=x[p]+1;
        j=y[p]-1;
        while (i<8 && j>=0) {
            if (ch[i][j]) return 0;
            ++i;--j;
        }
    }
    return 1;
}