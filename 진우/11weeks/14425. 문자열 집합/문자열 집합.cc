#include <iostream>
#include <string>
#include <set>   // set 컨테이너 사용

using namespace std;

int main() {

    int S, M;
    cin >> S >> M;   // S: 집합에 포함된 문자열 수, M: 확인할 문자열 수

    set<string> S_words;  // 문자열 집합 생성 (자동 정렬 + 중복 제거)
    string word;

    // S개의 문자열 입력 후 집합에 추가
    for (int i = 0; i < S; i++) {
        cin >> word;
        S_words.insert(word);  // insert: 집합에 문자열 추가
    }

    int cnt = 0;  // 포함되는 문자열 개수 카운트

    // M개의 문자열 입력 후 집합에 존재 여부 확인
    for (int i = 0; i < M; i++) {
        cin >> word;
        // find()로 word가 집합 안에 있는지 확인
        // find()가 반환하는 iterator가 .end()가 아니면 존재
        if (S_words.find(word) != S_words.end()) cnt++;
    }

    // 포함된 문자열 개수 출력
    cout << cnt << "\n";
    return 0;
}
