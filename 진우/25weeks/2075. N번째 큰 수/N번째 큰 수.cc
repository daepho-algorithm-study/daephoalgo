#include <iostream>
#include <queue>   

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                 

    int N;
    cin >> N;   // N 입력 (총 N x N개의 숫자를 입력받음)

    /*
        최소 힙(min heap) 선언
        가장 "작은 값"이 top()에 위치
    */
    priority_queue<int, vector<int>, greater<int>> q;


    //총 N*N개의 숫자를 입력받음
    for (int i = 0; i < N * N; i++) {
        int x;
        cin >> x;     // 숫자 입력

        q.push(x);    // 우선순위 큐에 삽입

        /*
            큐의 크기가 N을 초과하면
            가장 작은 값을 제거

            항상 "큰 수 N개"만 남도록 유지
        */
        if (q.size() > N) {
            q.pop();  // 현재 가장 작은 값 제거
        }
    }

    /*
        반복이 끝나면
        큐에는 전체 숫자 중 "가장 큰 값 N개"만 남아 있음

        그 중 가장 작은 값(top)은
        전체에서 N번째로 큰 값
    */
    cout << q.top() << "\n";

    return 0;
}