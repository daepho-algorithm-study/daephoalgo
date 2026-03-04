#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N: 나무의 개수, M: 필요한 나무의 총 길이
int N;
long long M;

/*
 이분 탐색 함수
 - tree : 각 나무의 높이를 저장한 벡터
 - x    : 나무 높이의 최댓값 (절단 높이 탐색의 상한)
 - 반환값: 필요한 길이 M 이상을 얻을 수 있는 최대 절단 높이
*/
int binary_search(vector<int>& tree, int x) {

    int left = 0;   // 절단 높이의 최소값
    int right = x;  // 절단 높이의 최대값
    
    int answer = 0; // 조건을 만족하는 최대 절단 높이 저장

    // 절단 높이에 대해 이분 탐색 수행
    while (left <= right) {
        int mid = (left + right) / 2; // 현재 탐색 중인 절단 높이

        long long cnt = 0; 
        // cnt: 현재 절단 높이(mid)로 나무를 잘랐을 때
        //      얻을 수 있는 나무 길이의 총합
        //      여러 나무 길이를 누적하므로 int 오버플로우 방지를 위해 long long 사용

        // 모든 나무를 순회하며 잘린 나무 길이 계산
        for (int i = 0; i < N; i++) {
            // 나무 높이가 절단 높이보다 클 경우만 나무를 얻을 수 있음
            if (tree[i] >= mid) {
                cnt += tree[i] - mid;
            }
        }

        // 필요한 나무 길이 M 이상을 얻을 수 있는 경우
        if (cnt >= M) {
            answer = mid;    // 현재 절단 높이는 가능하므로 저장
            left = mid + 1;  // 더 높은 절단 높이가 가능한지 탐색
        }
        // 필요한 길이를 얻지 못한 경우
        else {
            right = mid - 1; // 절단 높이를 낮춰 다시 탐색
        }
    }

    return answer; // 조건을 만족하는 최대 절단 높이 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; // 나무 개수와 필요한 나무 길이 입력

    vector<int> tree(N); // 나무 높이를 저장할 벡터
    int mx = 0;          // 나무 높이 중 최댓값 저장

    // 나무 높이 입력 및 최대 높이 계산
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        mx = max(mx, tree[i]);
    }

    // 이분 탐색을 통해 최적의 절단 높이 출력
    cout << binary_search(tree, mx) << "\n";

    return 0;
}