#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> // ::toupper

using namespace std;

int main() {
    string word;
    cin >> word;

    vector<int> alpa(26, 0);

    // 대문자로 변환
    transform(word.begin(), word.end(), word.begin(), ::toupper);

    // 각 알파벳 카운트
    for (char c : word) {
        alpa[c - 'A']++;
    }

    // 최댓값 찾기
    int mx = *max_element(alpa.begin(), alpa.end());
    int count = 0;
    char result;

    // 최댓값이 몇 개 있는지 확인
    for (int i = 0; i < 26; i++) {
        if (alpa[i] == mx) {
            count++;
            result = 'A' + i;
        }
    }

    // 출력
    if (count > 1) cout << "?" << endl;
    else cout << result << endl;

    return 0;
}
