#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);                

    long long A, B;
    cin >> A >> B;                   // 구간 시작(A)과 끝(B) 입력
    
    // 만약 A가 B보다 크면 서로 바꿔줌
    if (A > B) {
        long long temp = A;          
        A = B;
        B = temp;
    }
    
    // 구간의 길이 계산 (A~B 포함)
    long long len = B - A + 1;

    // 등차수열 합 공식 적용
    // sum = (첫 항 + 마지막 항) * 항 개수 / 2
    long long result = (A + B) * len / 2;

    cout << result << "\n";          

    return 0;
}
