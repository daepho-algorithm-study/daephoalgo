#include <iostream>

using namespace std;

// ---------------------------
// 별 찍기 재귀 함수
// i, j : 현재 좌표
// num : 현재 블록 크기 (재귀마다 1/3로 줄어듦)
// ---------------------------
void star(int i, int j, int num)
{
    // 현재 블록에서 가운데 블록이면 공백
    // (i/num)%3==1 → 현재 블록 안에서 가운데 행
    // (j/num)%3==1 → 현재 블록 안에서 가운데 열
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else
    {
        // 더 이상 나눌 수 없으면 별 출력 (기저 조건)
        if (num == 1) cout << '*';
        // 블록을 3으로 나누어 재귀 호출
        else star(i, j, num / 3);
    }
}

int main() {
    int N;
    cin >> N;  // 별을 찍을 전체 크기 N 입력 (3^k)

    // 0 ~ N-1 좌표를 반복하며 별 또는 공백 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            star(i, j, N); // 각 좌표에 대해 재귀 호출
        cout << '\n'; // 한 행 끝나면 줄 바꿈
    }

    return 0;
}
