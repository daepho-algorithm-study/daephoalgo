#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cin >> text;

    int result = 0;

    // 알파벳 A~Z에 대응하는 다이얼 값
    int dial[26] = {
        3,3,3,   // A,B,C
        4,4,4,   // D,E,F
        5,5,5,   // G,H,I
        6,6,6,   // J,K,L
        7,7,7,   // M,N,O
        8,8,8,8, // P,Q,R,S
        9,9,9,   // T,U,V
        10,10,10,10 // W,X,Y,Z
    };

    for (char c : text) {
        result += dial[c - 'A']; // 바로 매핑
    }

    cout << result << endl;
    return 0;
}
