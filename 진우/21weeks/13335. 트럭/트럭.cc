#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, L;
    cin >> n >> w >> L;   // n: 트럭 수, w: 다리 길이, L: 다리 최대 하중

    queue<int> truck;     // 남은 트럭들의 무게를 저장하는 큐
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        truck.push(x);    // 입력 순서대로 큐에 저장
    }

    queue<int> bridge;    // 다리를 나타내는 큐
    for (int i = 0; i < w; i++) {
        bridge.push(0);   // 초기에는 다리가 비어있으므로 0으로 채움
    }

    int time = 0;         // 경과 시간
    int weight = 0;       // 다리 위 트럭 총 무게

    // ===============================
    // 트럭이 모두 다리를 지나갈 때까지 반복
    // ===============================
    while (!truck.empty()) {
        // 다리 맨 앞 트럭이 다리를 다 지나감 → 큐에서 제거
        weight -= bridge.front();
        bridge.pop();
        
        // 다음 트럭을 다리에 올릴 수 있는지 확인
        if (weight + truck.front() <= L) {
            // 다리 하중을 초과하지 않으면 트럭 올리기
            bridge.push(truck.front());
            weight += truck.front();
            truck.pop();   // 트럭 큐에서 제거
        }
        else {
            // 다리 하중 초과 → 빈 칸(0) 올리기
            bridge.push(0);
        }
        time++;        // 1초 경과
    }

    // ===============================
    // 마지막 트럭이 다리를 완전히 지나갈 때까지
    // ===============================
    while (!bridge.empty()) {
        bridge.pop();     // 다리에서 한 칸씩 제거
        time++;           // 1초 경과
    }

    cout << time << "\n";  // 최종 시간 출력

    return 0;
}
