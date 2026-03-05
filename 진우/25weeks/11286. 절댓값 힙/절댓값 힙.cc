#include <iostream>
#include <queue>
#include <vector>
#include <cmath>   // abs() 사용을 위해 필요

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(nullptr);                 

    int N;        // 연산 개수
    cin >> N;     // N 입력

    /*
        우선순위 큐 선언

        priority_queue<
            저장할 자료형,
            내부 컨테이너,
            비교 방식
        >

        pair<int,int> 형태로 저장
        → first  : 절댓값
        → second : 실제 값

        greater<pair<int,int>> 를 사용하여
        "최소 힙" 형태로 구성
    */
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> 
        q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        // 입력값이 0이면 → 가장 작은 값 출력
        if (x == 0) {

            // 큐가 비어있다면
            if (q.empty()) {
                cout << 0 << "\n";
            }
            else {
                /*
                    top()은 가장 우선순위가 높은 pair 반환
                    pair.first  = 절댓값
                    pair.second = 실제 값

                    우리는 실제 값을 출력해야 하므로 second 사용
                */
                cout << q.top().second << "\n";
                q.pop();   // 출력 후 제거
            }
        }
        else {
            /*
                0이 아닌 경우
                (절댓값, 실제값) 형태로 저장

                절댓값 작은 수 우선
                절댓값 같으면 실제 값 작은 수(음수) 우선
            */
            q.push({ abs(x), x });
        }
    }

    return 0;
}