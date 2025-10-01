#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;   // 입력 문자열 (예: "baekjoon")

    // 알파벳 26자의 첫 등장 위치를 저장하는 벡터
    // 초기값은 -1 (아직 등장하지 않은 경우)
    vector<int> num(26, -1);

    // 문자열 S를 순회하면서 각 문자의 첫 등장 위치 기록
    for (int i = 0; i < (int)S.size(); i++) {
        int idx = S[i] - 'a';   // 현재 문자의 알파벳 인덱스 (a=0, z=25)
        if (num[idx] == -1) {   // 처음 등장한 경우에만 위치 저장
            num[idx] = i;       // 해당 알파벳의 첫 등장 인덱스 기록
        }
    }

    // 결과 출력
    // 각 알파벳 a~z의 첫 등장 위치를 공백으로 구분하여 출력
    // 등장하지 않은 문자는 -1 출력됨
    for (int i = 0; i < (int)num.size(); i++) {
        cout << num[i] << " ";
    }
    
    return 0;
}
