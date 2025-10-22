#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string N;
    int B;
    cin >> N >> B;

    int len = N.size();
    reverse(N.begin(), N.end());
    
    int result = 0;
    int num = 0;

    for (int i = 0; i < len; i++) {
        if ('A' <= N[i] && N[i] <= 'Z') {
            num = (N[i] - 'A') + 10;
        }
        else {
            num = N[i] - '0';
        }

        int X = 1;
        for (int j = 0; j < i; j++) {
            X *= B;
        }

        result += num * X;
    }

    cout << result << "\n";

    return 0;
}
