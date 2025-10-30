#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;  
    // A: 낮에 올라가는 거리
    // B: 밤에 미끄러지는 거리
    // V: 나무 막대의 높이

    // 마지막 날은 밤에 미끄러지지 않으므로,
    // (V - A)만큼의 높이를 "하루 순이득 (A - B)"로 나누어
    // 달팽이가 마지막 날 이전까지 올라가야 하는 일수를 구함
    int x = (V - A) / (A - B);

    // 나누어떨어지지 않으면 하루가 더 필요하므로 +1
    if ((V - A) % (A - B) != 0) {
        x += 1;
    }

    // 마지막 날(정상 도착하는 날)을 포함하여 총 일수 계산
    int cnt = x + 1;

    cout << cnt << "\n";  // 결과 출력
    return 0;
}
