#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

// 정육면체와 원기둥 크기 저장 배열
int cube[100], cylinder[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // 정육면체와 원기둥 크기 배열 인덱스 변수 할당
    int n, a = 0, b = 0;
    string s;
    cin >> n;
    // 블록 크기 저장
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "cube")
            cin >> cube[a++];
        else
            cin >> cylinder[b++];
    }
    // 블록 크기 정렬
    sort(cube, cube + a);
    sort(cylinder, cylinder + b);
    // 정답 출력 배열 할당
    pair<bool, int> p[100];
    // 탐색 변수 할당
    int x = 0, y = 0, k = 0;
    // 정육면체와 원기둥 크기 비교 후 정답 배열에 저장
    while (x < a || y < b)
    {
        // 남은 원기둥이 없거나 원기둥보다 큐브가 작다면 큐브를 위에 배치
        if (x < a && (y == b || cube[x] * sqrt(2) <= 1.0 * cylinder[y] * 2))
            p[k++] = {false, cube[x++]};
        // 남은 큐브가 없거나 원기둥이 큐브보다 작다면 원기둥을 위에 배치
        else if (y < b && (x == a || cube[x] >= cylinder[y] * 2))
            p[k++] = {true, cylinder[y++]};
        // 크기가 겹친다면 impossible 출력 후 종료
        else
        {
            cout << "impossible";
            return 0;
        }
    }
    // 정답 배열에 저장된 순서대로 출력
    for (int i = 0; i < n; i++)
    {
        if (!p[i].first)
            cout << "cube ";
        else
            cout << "cylinder ";
        cout << p[i].second << "\n";
    }
    return 0;
}