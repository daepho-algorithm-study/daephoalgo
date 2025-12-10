#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct spot
{
    ll x, y; // 점 위치 구조체 설정
};

// spot 오름차순 정렬을 위한 비교 함수 정의
bool cmp1(spot a, spot b);
// 벡터 방향 확인 함수 정의
ll ccw(spot a, spot b, spot c);
// 시작점에 대해 반시계 방향 정렬을 위한 비교 함수 정의
bool cmp2(spot a, spot b);

// 점 위치 저장 배열
vector<spot> p;
// 다각형 구성 점 저장 스택
spot stack[100001];
int top = 0; // 스택 최상단 위치 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    // 배열 크기 설정
    p.resize(n);
    // 점 위치 저장
    for (auto &s : p)
        cin >> s.x >> s.y;
    // y축 우선으로 우선 정렬
    sort(p.begin(), p.end(), cmp1);
    // 시작점을 기준으로 반시계 방향 정렬
    sort(p.begin() + 1, p.end(), cmp2);
    // 스택에 시작점과 첫번째 점 삽입
    stack[top++] = p[0], stack[top++] = p[1];
    for (int i = 2; i < n; i++)
    {
        // 점이 스택 상단 두 점을 이은 선분 기준 왼쪽이 아닐 때
        while (top >= 2 && ccw(stack[top - 2], stack[top - 1], p[i]) <= 0)
            // 왼쪽인 경우가 될 때까지 스택에서 값 추출
            top--;
        // 왼쪽을 유지한 상태에서 점 스택에 삽입
        stack[top++] = p[i];
    }
    cout << top;
    return 0;
}

bool cmp1(spot a, spot b)
{
    // y축을 우선 정렬
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}

bool cmp2(spot a, spot b)
{
    // 시작점을 기준으로 외적 계산
    ll result = ccw(p[0], a, b);
    // 외적이 양수면 반시계 방향
    if (result)
        return result > 0;
    // 외적이 0이면 같은 직선 상에 존재하므로 가까운 순으로 정렬
    return cmp1(a, b);
}

ll ccw(spot a, spot b, spot c)
{
    // 벡터 외적 계산
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}