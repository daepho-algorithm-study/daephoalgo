#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int len = s.size();

    long long zero = 0;      // 총 빈 칸 개수 (0)
    long long cnt = 0;   // 빈 칸 뒤에 빈 칸 있는 경우

    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            zero++;
            // 다음 칸도 0인지 확인 (원형 배열)
            if (s[(i + 1) % len] == '0') {
                cnt++;
            }
        }
    }

    // 확률 비교 (분수 비교)
    long long shoot = cnt * len;      // shoot 확률 비교용 분자
    long long rotate = zero * zero; // rotate 확률 비교용 분자

    if (shoot == rotate) {
        cout << "EQUAL" << "\n";
    }
    else if (shoot > rotate) {
        cout << "SHOOT" << "\n";
    }
    else {
        cout << "ROTATE" << "\n";
    }

    return 0;
}
