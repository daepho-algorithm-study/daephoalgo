#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {

		int N, M;
		cin >> N >> M;

		queue<pair<int, int>> q;   // (우선순위, 인덱스)
		priority_queue<int> pq;    // 현재 남아있는 최대 우선순위

		for (int i = 0; i < N; i++) {
			int x;
			cin >> x;

			q.push({ x, i });
			pq.push(x);
		}

		int cnt = 0;

		while (!q.empty()) {

			int p = q.front().first;
			int idx = q.front().second;

			q.pop();

			// 현재 문서가 가장 높은 우선순위가 아니면 뒤로 보냄
			if (p != pq.top()) {
				q.push({ p, idx });
			}
			else {

				cnt++;        // 출력 횟수 증가
				pq.pop();     // 해당 우선순위 제거

				// 찾고 있는 문서라면 종료
				if (idx == M) {
					cout << cnt << "\n";
					break;
				}
			}
		}
	}

	return 0;
}