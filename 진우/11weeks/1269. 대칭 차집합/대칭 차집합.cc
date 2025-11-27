#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {

    int A, B;
    cin >> A >> B;   // A: 집합 A의 원소 개수, B: 집합 B의 원소 개수

    int num;

    set<int> A_set;  // 집합 A를 저장할 set (중복 자동 제거 + 빠른 탐색)
    for (int i = 0; i < A; i++) {
        cin >> num;
        A_set.insert(num);  // 입력된 정수를 set에 삽입
    }

    int cnt = 0;  // A와 B의 교집합 원소 개수
    for (int i = 0; i < B; i++) {
        cin >> num;
        // B의 원소가 A_set에 존재하는지 확인
        if (A_set.find(num) != A_set.end()) {
            cnt += 1;  // 교집합 원소 개수 증가
        }
    }

    // 대칭 차집합 개수 = |A| + |B| - 2 * |A ∩ B|
    int result = A + B - (2 * cnt);

    cout << result << "\n";  // 결과 출력

    return 0;
}
