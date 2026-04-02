#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 각 노드의 왼쪽, 오른쪽 자식을 저장
// node[0] → 'A', node[1] → 'B' ...
pair<char, char> node[26];


// -----------------------------
// 전위 순회 (Preorder)
// 순서: 루트 → 왼쪽 → 오른쪽
// -----------------------------
void preorder(char n) {
    // '.'은 자식이 없다는 의미 → 종료
    if (n == '.') {
        return;
    }

    cout << n; // 1. 루트 출력
    preorder(node[n - 'A'].first);   // 2. 왼쪽 자식
    preorder(node[n - 'A'].second);  // 3. 오른쪽 자식
}


// -----------------------------
// 중위 순회 (Inorder)
// 순서: 왼쪽 → 루트 → 오른쪽
// -----------------------------
void inorder(char n) {
    if (n == '.') {
        return;
    }

    inorder(node[n - 'A'].first);    // 1. 왼쪽 자식
    cout << n;                       // 2. 루트 출력
    inorder(node[n - 'A'].second);   // 3. 오른쪽 자식
}


// -----------------------------
// 후위 순회 (Postorder)
// 순서: 왼쪽 → 오른쪽 → 루트
// -----------------------------
void postorder(char n) {
    if (n == '.') {
        return;
    }

    postorder(node[n - 'A'].first);  // 1. 왼쪽 자식
    postorder(node[n - 'A'].second); // 2. 오른쪽 자식
    cout << n;                       // 3. 루트 출력
}


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; // 노드 개수
    cin >> N;

    // 트리 정보 입력
    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;

        // parent를 인덱스로 변환해서 저장
        // 'A' → 0, 'B' → 1 ...
        node[parent - 'A'].first = left;   // 왼쪽 자식
        node[parent - 'A'].second = right; // 오른쪽 자식
    }

    // 루트는 항상 'A'로 시작
    preorder('A');   // 전위 순회
    cout << "\n";

    inorder('A');    // 중위 순회
    cout << "\n";

    postorder('A');  // 후위 순회

    return 0;
}