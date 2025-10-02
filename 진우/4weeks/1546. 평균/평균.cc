#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    double sum = 0.0;
    double M = 0.0;   // 최대값
    for (int i = 0; i < N; i++) {
        double score;
        cin >> score;
        sum += score;         // 합계 누적
        if (score > M) M = score;  // 최대값 갱신
    }

    // 새 평균 계산
    double avg = (sum / M) * 100.0 / N;
    cout << avg << '\n';

    return 0;
}
