#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    // 큐(A[i] == 0)만 deque에 저장
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) dq.push_back(B[i]);
    }

    int M;
    cin >> M;

    // 새 값은 앞에 넣고, 결과는 뒤에서 출력
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        dq.push_front(x);
        cout << dq.back() << " ";
        dq.pop_back();
    }

    return 0;
}
