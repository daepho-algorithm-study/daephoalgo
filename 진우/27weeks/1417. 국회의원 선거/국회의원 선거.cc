#include <iostream>
#include <queue>

using namespace std;

int main() {
    // C++ 입출력 속도 향상을 위한 설정
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;   // 후보자의 수 입력

	int one;
	cin >> one; // 다솜이(1번 후보)의 현재 표 수

	// 최대 힙(priority_queue)
	// 가장 큰 값이 항상 top()에 위치
	priority_queue<int> q;

	// 나머지 후보들의 표 수 입력
	for (int i = 1; i < N; i++) {
		int p;
		cin >> p;

		// 우선순위 큐에 저장
		// 가장 표가 많은 후보를 빠르게 찾기 위함
		q.push(p);
	}

	int cnt = 0;  // 매수(표를 가져온) 횟수

	// 큐가 빌 때까지 반복
	while (!q.empty()) {

        // 현재 가장 표가 많은 후보의 표 수가
        // 다솜이(one)보다 많거나 같으면
        // 그 후보의 표를 하나 뺏어와야 함
		if (q.top() >= one) {

            // 해당 후보의 표를 1 감소
			int temp = q.top() - 1;

            // 감소된 표를 다시 큐에 삽입
			q.push(temp);

            // 다솜이 표 +1
			one++;

            // 매수 횟수 증가
			cnt++;
		}

        // 가장 표가 많았던 후보 제거
		q.pop();
	}

    // 총 매수 횟수 출력
	cout << cnt << "\n";

	return 0;
}