#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++) {
        int money;
        cin >> money;

        int q_cnt = money / 25;
        money %= 25;

        int d_cnt = money / 10;
        money %= 10;

        int n_cnt = money / 5;
        money %= 5;

        int p_cnt = money / 1;
        money %= 1;

        cout << q_cnt << " " << d_cnt << " " << n_cnt << " " << p_cnt << "\n";
    }

    return 0;
}
