#include <iostream>
#include <vector>
using namespace std;
int main() {
    int W, P; // width; p partitions;
    cin >> W >> P;
    vector<bool> room(W + 1);
    int w;
    for(int w = 0; w < W + 1; w++) { // fill room with false;
        room[w] = false;
    }
    room[0] = true;
    room[W] = true; // two ends have partition.
    int p;
    for(p = 0; p < P; p++) {
        int ind;
        cin >> ind;
        room[ind] = true;
    }
    //for(int w = 0; w < W + 1; w++) { // fill room with false;
    //    cout << room[w] << " ";
    //}
    //cout << endl;
    int i;
    for(i = 1; i <= W; i++) {
        // check if i can exist.
        int j;
        for(j = 0; j < W; j++) {
            if (j + i > W) break;
            if (room[j] && room[j + i]) {
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}
