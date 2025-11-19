#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;  // 단어의 개수 입력

    set<string> s;  // 중복 제거용 set
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        s.insert(word);  // 입력된 단어를 set에 삽입 (중복 제거)
    }

    // set을 vector로 변환
    vector<string> words(s.begin(), s.end());

    // 먼저 사전순 정렬
    sort(words.begin(), words.end());

    // 길이 기준 안정 정렬 (길이가 같으면 사전순 유지)
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b){
        return a.size() < b.size();
    });

    // 정렬된 단어 출력 (범위 기반 for문 대신 인덱스 사용)
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << "\n";
    }

    return 0;
}
