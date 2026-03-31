#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 입력값을 저장할 배열
vector<int> arr;

// 각 레벨별 노드를 저장할 2차원 벡터
vector<vector<int>> answer;

// 중위 순회처럼 재귀로 노드를 탐색하고 각 깊이(depth)에 노드를 저장하는 함수
void inorder(int start, int end, int depth) {
    // start가 end보다 크면 범위를 벗어난 것이므로 종료
    if (start > end) {
        return;
    }

    // 중간 위치를 루트로 선택
    int root = (start + end) / 2;

    // 현재 깊이(depth)에 root 노드 값을 추가
    answer[depth].push_back(arr[root]);

    // 왼쪽 서브트리 탐색 (중간보다 왼쪽 범위)
    inorder(start, root - 1, depth + 1);

    // 오른쪽 서브트리 탐색 (중간보다 오른쪽 범위)
    inorder(root + 1, end, depth + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;  // 트리의 높이 입력

    int node = pow(2, k) - 1; // 완전 이진 트리 노드 총 개수 = 2^k - 1

    arr.resize(node);      // 노드 값을 입력받기 위해 벡터 크기 설정
    answer.resize(k);      // 각 깊이별 노드 저장 공간 설정

    // 노드 값 입력
    for (int i = 0; i < node; i++) {
        cin >> arr[i];
    }

    // 전체 배열 범위를 중위 순회로 탐색
    inorder(0, node - 1, 0);

    // 각 깊이별로 출력
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";  // 레벨별 출력 후 줄바꿈
    }

    return 0;
}