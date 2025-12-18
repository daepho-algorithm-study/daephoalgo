#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;               // N 입력받기
    
    int result = N * (N - 1);   // N개의 수로 만들 수 있는 서로 다른 순서쌍 개수 계산
    
    cout << result << "\n";     // 결과 출력
    
    return 0;
}
