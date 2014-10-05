//整行整行地读浮点数
//unknown input length, need to judge end of line
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    float x;
    string line;
    while (getline(cin, line)){
        istringstream s(line);
        while (s>>x){
            cout<<x<<"  ";
        }
        cout<<endl;
    }

    exit(0);
}