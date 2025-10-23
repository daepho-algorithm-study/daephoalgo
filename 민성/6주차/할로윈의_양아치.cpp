#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x);          // root 노드 탐색 함수 정의
void merge(int x, int y); // 병합 함수 정의
int candy[30001];         // 아이들이 받은 사탕 수 저장 배열
int parent[30001];        // root 노드 저장 배열
int ps[30001];            // 집합 크기 저장 배열
int sm[30001];            // 집합 내의 사탕 수 저장 배열
int dp[3001];             // dp 배열 할당

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> candy[i];  // 사탕 수 저장
        parent[i] = i;    // 초기 root 노드 할당
        ps[i] = 1;        // 초기 크기 1 집합 생성
        sm[i] = candy[i]; // 크기 1 집합 내의 사탕 수 저장
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        merge(a, b); // 친구 관계끼리 병합
    }
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
        {
            int s = ps[i], v = sm[i]; // 크기와 가치 할당
            for (int j = k - s - 1; j >= 0; j--)
                dp[j + s] = max(dp[j + s], dp[j] + v); // 냅색 알고리즘 실행
        }
    int mx = *max_element(dp, dp + k); // dp 배열 최대값 추출
    cout << mx;
    return 0;
}

int find(int x)
{
    if (parent[x] == x)
        return x;                       // root 노드면 return
    return parent[x] = find(parent[x]); // root 노드값을 해당 배열에 저장
}

void merge(int x, int y)
{
    x = find(x), y = find(y); // root를 비교하기 위해 각 root 노드 할당
    if (x == y)
        return;
    if (ps[x] < ps[y])
        swap(x, y); // 집합 크기가 큰 쪽으로 병합
    parent[y] = x;
    ps[x] += ps[y];
    sm[x] += sm[y];
}