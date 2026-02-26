#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 랜선 개수(K)와 필요한 랜선 수(N)
int K, N;

/*
 * binary_search
 * - 랜선 배열 lan에서 가능한 최대 랜선 길이를 이진 탐색
 * - x: 현재 배열에서 가장 긴 랜선 길이 (탐색의 상한)
 * - 반환값: 만들 수 있는 랜선의 최대 길이
 */
long long binary_search(vector<long long>& lan, long long x) {

    long long left = 1;    // 랜선 최소 길이
    long long right = x;   // 랜선 최대 길이
    long long answer = 0;  // 조건을 만족하는 최대 길이

    while (left <= right) {
        long long mid = (left + right) / 2;  // 현재 길이 시도

        int cnt = 0;
        // mid 길이로 잘랐을 때 랜선 몇 개 만들 수 있는지 계산
        for (int i = 0; i < K; i++) {
            cnt += lan[i] / mid;
        }

        if (cnt >= N) {
            // N개 이상 만들 수 있음 → 더 긴 길이도 가능
            answer = mid;
            left = mid + 1;
        }
        else {
            // N개 못 만들면 길이를 줄임
            right = mid - 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // K: 기존 랜선 수, N: 필요한 랜선 수
    cin >> K >> N;

    vector<long long> lan(K); // 기존 랜선 길이 저장
    long long mx = 0;         // 배열에서 가장 긴 랜선 길이

    // 랜선 길이 입력
    for (int i = 0; i < K; i++) {
        cin >> lan[i];
        mx = max(mx, lan[i]); // 최댓값 갱신
    }

    // 이진 탐색으로 최대 길이 계산 후 출력
    cout << binary_search(lan, mx) << "\n";

    return 0;
}