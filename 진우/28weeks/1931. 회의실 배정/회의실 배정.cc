#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 성능 최적화 (C++ 표준 입출력 속도 향상)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int I; // 전체 회의(또는 트럭)의 개수
    cin >> I;

    // {종료 시간, 시작 시간} 순으로 저장할 벡터
    // pair의 첫 번째 인자를 기준으로 정렬되므로 '종료 시간'을 먼저 넣습니다.
    vector<pair<int, int>> time;

    for (int i = 0; i < I; i++) {
        int s, e;
        cin >> s >> e;                

        // 정렬을 위해 {끝나는 시간, 시작하는 시간} 순으로 삽입
        time.push_back({ e, s });    
    }

    // 종료 시간이 빠른 순서대로 오름차순 정렬 (Greedy의 핵심)
    // 종료 시간이 같다면 시작 시간이 빠른 순서대로 정렬됩니다.
    sort(time.begin(), time.end());

    int cnt = 0;     // 최종 선택된 회의의 개수
    int now = -1;    // 현재 선택된 회의가 끝나는 시각 (초기값은 아주 이른 시간)

    // 모든 회의를 순차적으로 확인
    for (int i = 0; i < time.size(); i++) {
        // 현재 선택된 회의가 끝난 시각(now)보다 
        // 조사 중인 회의의 시작 시간(time[i].second)이 같거나 늦다면?
        if (now <= time[i].second) {
            cnt++;               // 회의 확정, 개수 증가
            now = time[i].first; // 기준 시각을 현재 회의가 끝나는 시간으로 갱신
        }
    }

    // 결과 출력 (최대 배정 가능한 회의 수)
    cout << cnt << "\n";              

    return 0;
}