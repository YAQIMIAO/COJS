#include <iostream>
using namespace std;
int press(int bot, int state);
void printb(int b){
    while (b!=0) {
        cout <<b%2;
        b=b/2;
    }
}
int main() {
    int s;
    cin >>s;
    cout <<press(4,s)<<endl;
    printb(press(4,s));
    cout <<endl;
    return 0;
}
int press(int bot, int state) {
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