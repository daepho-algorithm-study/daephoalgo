#include <iostream>
#include <vector>

using namespace std;

int find(int x);          // root 노드 탐색 함수 정의
void merge(int x, int y); // 노드 연결 함수 정의
int parent[51];           // 부모 노드를 가리키는 배열
vector<int> party;        // 파티의 사람들을 그룹화시킬 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, p, num, rt = 0, g;
    for (int i = 1; i <= 50; i++)
        parent[i] = i; // 그룹화 전 상태 초기화
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
    {
        if (i == 0)
        {
            cin >> rt; // 진실을 아는 첫번째 사람 번호 저장
            continue;
        }
        cin >> num;
        merge(rt, num); // 진실을 아는 사람들끼리 그룹화
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            if (j == 0)
            {
                cin >> g; // 그룹 대표 번호 저장
                continue;
            }
            cin >> num;
            merge(g, num); // 해당 파티 참석자들 그룹화
        }
        party.push_back(g); // 그룹화된 파티 저장
    }
    int cnt = 0; // 과장이 가능한 파티 수 카운팅 변수
    for (int i = 0; i < m; i++)
        if (find(rt) != find(party[i]))
            cnt++; // 진실을 아는 그룹과 다른 그룹이면 카운트 증가
    cout << cnt;
    return 0;
}

int find(int x)
{
    if (x == parent[x])
        return x;                       // root 노드를 찾으면 return
    return parent[x] = find(parent[x]); // 경로 압축
}

void merge(int x, int y)
{
    x = find(x), y = find(y); // 각 노드의 root를 탐색
    if (x == y)               // root가 같다면 스킵
        return;
    if (x < y)
        parent[y] = x; // root의 수가 작은 쪽이 큰 쪽의 root로 지정
    else
        parent[x] = y;
}