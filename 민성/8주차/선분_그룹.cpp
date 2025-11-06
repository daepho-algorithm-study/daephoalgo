#include <iostream>
#include <algorithm>

using namespace std;

// 외적 방향 계산 함수 정의
int ccw(int x1, int y1, int x2, int y2, int x3, int y3);
// 선분 교차 체크 함수 정의
bool cross(int l1[4], int l2[4]);
int parent(int x);        // 루트 노드 탐색 함수 정의
void merge(int x, int y); // 그룹 병합 함수 정의
int line[3001][4];        // 선분 좌표 저장 배열
int root[3001];           // 루트 노드 저장 배열
int gs[3001];             // 그룹 크기 저장 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        root[i] = i; // 루트와 그룹 크기 초기화
        gs[i] = 1;
        for (int j = 0; j < 4; j++)
            cin >> line[i][j]; // 선분 좌표 저장
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (cross(line[i], line[j]))
                merge(i, j); // 선분 교차 시 병합
    int cnt = 0, mx = 0;     // 그룹 수와 최대 그룹 크기 저장 변수
    for (int i = 1; i <= n; i++)
        if (parent(i) == i)
        {
            cnt++; // 그룹 카운팅
            if (mx < gs[i])
                mx = gs[i]; // 최대값 갱신
        }
    cout << cnt << "\n" << mx;
    return 0;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
{
    // 외적 계산값 할당
    int s = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
    if (s > 0)
        return 1;
    else if (s < 0)
        return -1;
    else
        return 0;
}

bool cross(int l1[4], int l2[4])
{
    // 한 선분과 다른 선분의 한 점의 외적값 계산
    int s1 = ccw(l1[0], l1[1], l1[2], l1[3], l2[0], l2[1]),
        s2 = ccw(l1[0], l1[1], l1[2], l1[3], l2[2], l2[3]),
        s3 = ccw(l2[0], l2[1], l2[2], l2[3], l1[0], l1[1]),
        s4 = ccw(l2[0], l2[1], l2[2], l2[3], l1[2], l1[3]);
    if (s1 * s2 <= 0 && s3 * s4 <= 0)
    {
        if (s1 * s2 == 0 && s3 * s4 == 0)
        {
            // 점 위치 비교를 위한 할당
            pair<int, int> p1 = {l1[0], l1[1]},
                           p2 = {l1[2], l1[3]},
                           p3 = {l2[0], l2[1]},
                           p4 = {l2[2], l2[3]};
            if (p1 > p2)
                swap(p1, p2);
            if (p3 > p4)
                swap(p3, p4);
            if (p3 <= p2 && p1 <= p4)
                return true; // 일직선으로 포개져 있으면 true 리턴
            else
                return false; // 일직선으로 떨어진 경우 false 리턴
        }
        else
            return true; // 일직선이 아닌 교차이면 true 리턴
    }
    else
        return false; // 교차점이 존재하지 않으면 false 리턴
}

int parent(int x)
{
    if (root[x] == x)
        return x;                     // 루트 노드 탐색 완료 시 리턴
    return root[x] = parent(root[x]); // 루트 노드를 찾을 때까지 탐색
}

void merge(int x, int y)
{
    x = parent(x), y = parent(y); // 각각 루트 노드 할당
    if (x == y)
        return; // root가 같으면 스킵
    if (gs[x] < gs[y])
        swap(x, y); // x가 큰 그룹이 되게 전환
    root[y] = x;    // 그룹 병합
    gs[x] += gs[y]; // 그룹 크기 합산
}