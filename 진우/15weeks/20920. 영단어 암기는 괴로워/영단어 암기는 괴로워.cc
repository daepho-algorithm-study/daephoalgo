#include <iostream>   // 표준 입출력
#include <vector>     // vector 사용
#include <set>        // set 사용 (중복 제거)
#include <map>        // map 사용 (단어별 빈도 기록)
#include <algorithm>  // sort 사용
#include <string>     // string 사용

using namespace std;

// 전역 map: 단어별 등장 횟수 기록
map<string, int> cnt;

// 사용자 정의 정렬 함수
bool compare(string a, string b) {
    if (cnt[a] != cnt[b])           // 1. 빈도 내림차순
        return cnt[a] > cnt[b];

    if (a.length() != b.length())   // 2. 길이 내림차순
        return a.length() > b.length();

    return a < b;                   // 3. 사전순 오름차순
}

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 최적화
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;  // 단어 개수 N과 최소 길이 M 입력

    set<string> words;  // 중복 제거용 set

    // 단어 입력 처리
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        if (word.length() >= M) {      // 최소 길이 M 이상인 단어만 처리
            cnt[word]++;               // 단어 빈도 증가
            words.insert(word);        // set에 넣어 중복 제거
        }
    }

    // set -> vector 변환 (sort를 위해)
    vector<string> wordbook(words.begin(), words.end());

    // vector 정렬 (compare 기준)
    sort(wordbook.begin(), wordbook.end(), compare);

    // 정렬된 단어 출력
    for (int i = 0; i < wordbook.size(); i++) {
        cout << wordbook[i] << '\n';
    }

    return 0;  // 프로그램 종료
}
