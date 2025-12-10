#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> s;   // 대기열 역할 (옆으로 빼두는 공간)
    int current = 1; // 현재 순서대로 나와야 하는 번호 (1부터 시작)

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // **지금 들어온 번호가 순서대로 나와야 한다면**
        if (num == current) {
            current++;  // 바로 통과
        } 
        else {
            // 순서가 아니라면 대기열(스택)에 보관
            s.push(num);
        }

        // **대기열에서 꺼낼 수 있을 때 반복해서 꺼내기**
        while (!s.empty() && s.top() == current) {
            s.pop();
            current++;
        }
    }

    // 대기열이 모두 비었으면 모든 번호가 순서대로 나왔다
    if (s.empty()) cout << "Nice" << "\n";
    else cout << "Sad" << "\n";

    return 0;
}
