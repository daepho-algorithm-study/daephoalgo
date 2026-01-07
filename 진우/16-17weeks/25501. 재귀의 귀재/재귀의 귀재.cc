#include <iostream>   
#include <string>     

using namespace std;

// 재귀 함수가 호출된 횟수를 세기 위한 전역 변수
int cnt = 0;

// 문자열 s의 l(왼쪽)부터 r(오른쪽)까지가 팰린드롬인지 재귀적으로 검사하는 함수
int recursion(const string& s, int l, int r) {
    cnt++;  // recursion 함수가 호출될 때마다 카운트 증가

    // 종료 조건 1: 중앙까지 도달한 경우 (팰린드롬 성립)
    if (l >= r) {
        return 1;
    }
    // 종료 조건 2: 양쪽 문자가 다르면 팰린드롬이 아님
    else if (s[l] != s[r]) {
        return 0;
    }
    // 양쪽 문자가 같으면 한 칸씩 안쪽으로 이동하여 재귀 호출
    else {
        return recursion(s, l + 1, r - 1);
    }	
}

// 문자열 전체에 대해 팰린드롬 여부를 검사하는 함수
int isPalindrome(const string& s) {
    cnt = 0;  // 새로운 문자열 검사 전에 재귀 호출 횟수 초기화
    // 문자열의 시작(0)부터 끝(length - 1)까지 검사
    return recursion(s, 0, s.length() - 1);
}

int main() {
    int N;
    cin >> N;  // 검사할 문자열 개수 입력

    string word;
    // N개의 문자열을 하나씩 입력받아 팰린드롬 여부 검사
    for (int i = 0; i < N; i++) {
        cin >> word;  // 문자열 입력
        // 팰린드롬 결과(1 또는 0)와 재귀 호출 횟수 출력
        cout << isPalindrome(word) << " " << cnt << "\n";
    }

    return 0;  
}
