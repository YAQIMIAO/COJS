//#include<stdio.h>
#include <iostream>
using namespace std;

int comb(int s, int ka, int kb) {
    if(s > ka + kb)
    {
        return 0;
    } else if (ka >= s || kb >= s) {
        return s + 1;
    }
    return ka+kb-s+1;
}

int solve(int a, int b)
{
    int i, count = 0;
    for(i = 0; i < 29; i++)
    {
        count += comb(((1 << i) - 1), a, b);
    }
    
    return count;
}

int main()
{
    /*int a = 7, b = 7;
    int ans;
    ans = solve(a, b);
    printf("%d\n", ans);(*/
    int N, n;
    cin >> N;
    for (n = 0; n < N; n++) {
        int a, b;
        cin >> a >> b;
        //cout << "a = "<< a << "b = " << b << endl;
        cout << solve(a, b) << endl;
        
    }
    return 0;
}
