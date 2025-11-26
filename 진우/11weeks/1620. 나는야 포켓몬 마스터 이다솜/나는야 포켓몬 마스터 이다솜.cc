#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    string name;

    // 문자열 이름 → 번호 저장
    map<string, int> pokedex;

    // 번호 → 이름 저장 (번호로 이름을 찾기 위해 사용)
    vector<string> num(N + 1); // 1번부터 사용하기 위해 N+1 크기

    // 포켓몬 이름 입력 (1번부터 N번까지)
    for (int i = 1; i <= N; i++) {
        cin >> name;
        pokedex[name] = i;  // 이름 → 번호 매핑
        num[i] = name;      // 번호 → 이름 매핑
    }

    // M개의 질문 처리
    for (int i = 0; i < M; i++) {
        cin >> name;

        // 첫 글자가 숫자인지 확인 → 숫자로 시작하면 번호 입력
        if ('0' <= name[0] && name[0] <= '9') {
            int idx = stoi(name);  // 문자열을 정수로 변환
            cout << num[idx] << "\n";  // 번호로 이름 출력
        }
        else {
            // 문자열 입력 → 이름으로 번호 찾기
            cout << pokedex[name] << "\n";
        }
    }

    return 0;
}
